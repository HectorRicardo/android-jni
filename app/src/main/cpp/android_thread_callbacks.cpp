//
// Created by hecto on 1/4/2022.
//

#include "android_thread_callbacks.hpp"

#include <jni.h>

AndroidThreadCallbacks::AndroidThreadCallbacks(JNIEnv *jniEnv, jobject callbacks)
    : jniEnv(jniEnv),
      callbacks(callbacks),
      onThreadStartedMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(callbacks),
                              "onThreadStart",
                              "()V")),
      onIterationCompleteMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(callbacks),
                              "onIterationComplete",
                              "(I)V")),
      onThreadFinishedMethodID(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(callbacks),
                              "onThreadFinished",
                              "()V"))
{}

void AndroidThreadCallbacks::onThreadStarted() const {
  jniEnv->CallVoidMethod(callbacks, onThreadStartedMethodID);
}

void AndroidThreadCallbacks::onIterationComplete(int iteration) const {
  jniEnv->CallVoidMethod(callbacks, onIterationCompleteMethodID, iteration);
}

void AndroidThreadCallbacks::onThreadFinished() const {
  jniEnv->CallVoidMethod(callbacks, onThreadFinishedMethodID);
}
