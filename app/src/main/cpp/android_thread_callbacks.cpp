//
// Created by hecto on 1/4/2022.
//

#include "android_thread_callbacks.hpp"

#include <jni.h>

AndroidThreadCallbacks::AndroidThreadCallbacks(JNIEnv *jniEnv,
                                               jobject callbacks) :
    AndroidThreadCallbacks(jniEnv,
                           callbacks,
                           jniEnv->GetObjectClass(callbacks)) {}

AndroidThreadCallbacks::AndroidThreadCallbacks(JNIEnv *jniEnv,
                                               jobject callbacks,
                                               jclass callbacksClass)
    : jniEnv(jniEnv), callbacks(callbacks),
      onThreadStartedMethodID(
          jniEnv->GetMethodID(callbacksClass, "onThreadStart", "()V")),
      onIterationCompleteMethodID(
          jniEnv->GetMethodID(callbacksClass, "onIterationComplete", "(I)V")),
      onThreadFinishedMethodID(
          jniEnv->GetMethodID(callbacksClass, "onThreadFinished", "()V")) {}

void AndroidThreadCallbacks::onThreadStarted() const {
  jniEnv->CallVoidMethod(callbacks, onThreadStartedMethodID);
}

void AndroidThreadCallbacks::onIterationComplete(int iteration) const {
  jniEnv->CallVoidMethod(callbacks, onIterationCompleteMethodID, iteration);
}

void AndroidThreadCallbacks::onThreadFinished() const {
  jniEnv->CallVoidMethod(callbacks, onThreadFinishedMethodID);
}
