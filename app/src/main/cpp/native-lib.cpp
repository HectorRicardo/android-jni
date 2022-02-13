#include <jni.h>
#include <thread>
#include <chrono>
#include "print.hpp"

class ThreadObject {
 public:
  ThreadObject(JNIEnv *jniEnv, jobject mainActivity)
      : jniEnv(jniEnv),
        mainActivity(mainActivity),
        onThreadStartMethodId(
            jniEnv->GetMethodID(jniEnv->GetObjectClass(mainActivity),
                                "onThreadStart",
                                "()V")) {}
  void callThreadStartedMethod() const {
    jniEnv->CallVoidMethod(mainActivity, onThreadStartMethodId);
  }
 private:
  JNIEnv *jniEnv;
  jobject mainActivity;
  jmethodID onThreadStartMethodId;
};

void callMethod(JNIEnv *env, jobject mainActivity) {
  jclass mainActivityClass = env->GetObjectClass(mainActivity);
  jmethodID
      j_method = env->GetMethodID(mainActivityClass, "onThreadStart", "()V");
  env->CallVoidMethod(mainActivity, j_method);
}

void threadBody(JNIEnv *env, jobject mainActivityGlobal) {
  ThreadObject t(env, mainActivityGlobal);
  for (int i = 0; i < 6; i++) {
    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
    t.callThreadStartedMethod();
  }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_remember_MainActivity_stringFromJNI(
    JNIEnv *env,
    jobject mainActivity) {
  callMethod(env, mainActivity);

  JavaVM *javaVM;
  env->GetJavaVM(&javaVM);

  jobject mainActivityGlobal = env->NewGlobalRef(mainActivity);

  std::thread thr([javaVM, mainActivityGlobal] {
    JNIEnv *env;
    javaVM->AttachCurrentThread(&env, nullptr);

    threadBody(env, mainActivityGlobal);

    env->DeleteGlobalRef(mainActivityGlobal);
    javaVM->DetachCurrentThread();
  });
  thr.detach();

  return env->NewStringUTF("Hello from C++");
}
