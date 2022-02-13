#include <jni.h>
#include <thread>
#include "AndroidBridge.hpp"
#include "common/thread_logic.hpp"

extern "C" JNIEXPORT void JNICALL
Java_com_example_remember_MainActivity_startThread(
    JNIEnv *env,
    jobject mainActivity) {
  JavaVM *javaVM;
  env->GetJavaVM(&javaVM);

  jobject mainActivityGlobal = env->NewGlobalRef(mainActivity);

  std::thread thr([javaVM, mainActivityGlobal] {
    JNIEnv *env;
    javaVM->AttachCurrentThread(&env, nullptr);

    AndroidBridge bridge(env, mainActivityGlobal);
    threadBody(bridge);

    env->DeleteGlobalRef(mainActivityGlobal);
    javaVM->DetachCurrentThread();
  });
  thr.detach();
}
