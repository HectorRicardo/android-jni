#include <jni.h>
#include <thread>
#include "AndroidThreadExecutionCallbacks.hpp"
#include "common/thread_logic.hpp"

extern "C" JNIEXPORT void JNICALL
Java_com_example_remember_MainActivity_startThread(
    JNIEnv *env,
    jclass,
    jobject threadExecutionCallbacks) {
  JavaVM *javaVM;
  env->GetJavaVM(&javaVM);

  jobject threadExecutionCallbacksGlobal =
      env->NewGlobalRef(threadExecutionCallbacks);

  std::thread thr([javaVM, threadExecutionCallbacksGlobal] {
    JNIEnv *env;
    javaVM->AttachCurrentThread(&env, nullptr);

    AndroidThreadExecutionCallbacks bridge(env, threadExecutionCallbacksGlobal);
    threadBody(bridge);

    env->DeleteGlobalRef(threadExecutionCallbacksGlobal);
    javaVM->DetachCurrentThread();
  });
  thr.detach();
}
