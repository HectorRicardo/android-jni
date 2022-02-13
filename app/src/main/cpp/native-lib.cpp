#include <jni.h>
#include <thread>
#include "AndroidThreadExecutionCallbacks.hpp"
#include "common/thread_logic.hpp"

extern "C" JNIEXPORT void JNICALL
Java_com_example_remember_MainActivity_startThread(
    JNIEnv *env,
    jclass,
    jobject threadHandler) {
  JavaVM *javaVM;
  env->GetJavaVM(&javaVM);

  jobject threadHandlerGlobal = env->NewGlobalRef(threadHandler);

  std::thread thr([javaVM, threadHandlerGlobal] {
    JNIEnv *env;
    javaVM->AttachCurrentThread(&env, nullptr);

    AndroidThreadExecutionCallbacks bridge(env, threadHandlerGlobal);
    threadBody(bridge);

    env->DeleteGlobalRef(threadHandlerGlobal);
    javaVM->DetachCurrentThread();
  });
  thr.detach();
}
