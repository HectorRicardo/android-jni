//
// Created by hecto on 1/4/2022.
//

#include <jni.h>
#include "android_thread_callbacks.hpp"

AndroidThreadCallbacks::AndroidThreadCallbacks(JNIEnv *jniEnv,
                                                   jobject threadCallbacks)
    : jniEnv(jniEnv),
      threadCallbacks(threadCallbacks),
      onThreadStartedMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(threadCallbacks),
                              "onThreadStart",
                              "()V")),
      onIterationCompleteMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(threadCallbacks),
                              "onIterationComplete",
                              "(I)V")),
      onThreadFinishedMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(threadCallbacks),
                              "onThreadFinished",
                              "()V")){}

void AndroidThreadCallbacks::onThreadStarted() const {
  jniEnv->CallVoidMethod(threadCallbacks, onThreadStartedMethodID);
}

void AndroidThreadCallbacks::onIterationComplete(int iteration) const {
  jniEnv->CallVoidMethod(threadCallbacks, onIterationCompleteMethodID, iteration);
}

void AndroidThreadCallbacks::onThreadFinished() const {
  jniEnv->CallVoidMethod(threadCallbacks, onThreadFinishedMethodID);
}