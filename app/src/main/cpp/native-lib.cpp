#include <jni.h>
#include <thread>
#include <chrono>
#include "print.hpp"

class ThreadObject {
 public:
  ThreadObject(JNIEnv *jniEnv, jobject mainActivity)
      : jniEnv(jniEnv),
        mainActivity(mainActivity),
        methodToBeCalledFromJNI(
            jniEnv->GetMethodID(jniEnv->GetObjectClass(mainActivity),
                                "methodToBeCalledFromJNI",
                                "()V")) {}
  void callThreadStartedMethod() const {
    jniEnv->CallVoidMethod(mainActivity, methodToBeCalledFromJNI);
  }
 private:
  JNIEnv *jniEnv;
  jobject mainActivity;
  jmethodID methodToBeCalledFromJNI;
};

void callJavaMethod(JNIEnv *env, jobject mainActivity) {
  jclass mainActivityClass = env->GetObjectClass(mainActivity);
  jmethodID
      j_method =
      env->GetMethodID(mainActivityClass, "methodToBeCalledFromJNI", "()V");
  env->CallVoidMethod(mainActivity, j_method);
}

void threadBody(JNIEnv *env, jobject mainActivityGlobal) {
  ThreadObject t(env, mainActivityGlobal);
  for (int i = 0; i < 5; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    t.callThreadStartedMethod();
  }
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_remember_MainActivity_jniMethod(
    JNIEnv *env,
    jobject mainActivity) {
  callJavaMethod(env, mainActivity);

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
}
