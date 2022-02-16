//
// Created by hecto on 1/4/2022.
//

#include <jni.h>
#include "AndroidThreadExecutionCallbacks.hpp"

AndroidThreadExecutionCallbacks::AndroidThreadExecutionCallbacks(JNIEnv *jniEnv,
                                                                 jobject threadCallbacks)
    : jniEnv(jniEnv),
      threadCallbacks(threadCallbacks),
      onThreadStartedMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(threadCallbacks),
                              "onThreadStart",
                              "()V")) {}

void AndroidThreadExecutionCallbacks::onThreadStarted() const {
  jniEnv->CallVoidMethod(threadCallbacks, onThreadStartedMethodID);
}
