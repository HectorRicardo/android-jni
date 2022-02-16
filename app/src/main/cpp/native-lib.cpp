#include <jni.h>
#include <thread>
#include "android_thread_callbacks.hpp"
#include "common/thread_logic.hpp"

extern "C" JNIEXPORT void JNICALL
Java_com_example_remember_MainActivity_startThread(
    JNIEnv *env,
    jclass,
    jobject threadCallbacks) {
  JavaVM *javaVM;
  env->GetJavaVM(&javaVM);

  jobject threadCallbacksGlobal = env->NewGlobalRef(threadCallbacks);

  std::thread([javaVM, threadCallbacksGlobal] {
    JNIEnv *env;
    javaVM->AttachCurrentThread(&env, nullptr);

    Android_Thread_Callbacks callbacks(env, threadCallbacksGlobal);
    thread_logic(callbacks);

    env->DeleteGlobalRef(threadCallbacksGlobal);
    javaVM->DetachCurrentThread();
  }).detach();
}
