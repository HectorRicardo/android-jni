//
// Created by hecto on 1/4/2022.
//

#include <jni.h>
#include "AndroidThreadExecutionCallbacks.hpp"

AndroidThreadExecutionCallbacks::AndroidThreadExecutionCallbacks(JNIEnv *jniEnv,
                                                                 jobject threadHandler)
    : jniEnv(jniEnv),
      threadHandler(threadHandler),
      onThreadStartedMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(threadHandler),
                              "onThreadStart",
                              "()V")) {}

void AndroidThreadExecutionCallbacks::onThreadStarted() const {
  jniEnv->CallVoidMethod(threadHandler, onThreadStartedMethodID);
}
