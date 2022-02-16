#include <jni.h>
#include <thread>
#include "AndroidThreadExecutionCallbacks.hpp"
#include "common/thread_logic.hpp"

extern "C" JNIEXPORT void JNICALL
Java_com_example_remember_MainActivity_startThread(
    JNIEnv *env,
    jclass,
    jobject threadCallbacks) {
  JavaVM *javaVM;
  env->GetJavaVM(&javaVM);

  jobject threadCallbacksGlobal = env->NewGlobalRef(threadCallbacks);

  std::thread thr([javaVM, threadCallbacksGlobal] {
    JNIEnv *env;
    javaVM->AttachCurrentThread(&env, nullptr);

    AndroidThreadExecutionCallbacks bridge(env, threadCallbacksGlobal);
    threadBody(bridge);

    env->DeleteGlobalRef(threadCallbacksGlobal);
    javaVM->DetachCurrentThread();
  });
  thr.detach();
}
