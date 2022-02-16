//
// Created by hecto on 1/4/2022.
//

#include <jni.h>
#include "android_thread_callbacks.hpp"

Android_Thread_Callbacks::Android_Thread_Callbacks(JNIEnv *jniEnv,
                                                   jobject threadCallbacks)
    : jniEnv(jniEnv),
      threadCallbacks(threadCallbacks),
      onThreadStartedMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(threadCallbacks),
                              "onThreadStart",
                              "()V")) {}

void Android_Thread_Callbacks::onThreadStarted() const {
  jniEnv->CallVoidMethod(threadCallbacks, onThreadStartedMethodID);
}
