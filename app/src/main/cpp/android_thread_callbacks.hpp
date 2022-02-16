//
// Created by hecto on 1/4/2022.
//

#ifndef MYAPP_ANDROID_THREAD_CALLBACKS_HPP
#define MYAPP_ANDROID_THREAD_CALLBACKS_HPP

#include <jni.h>
#include "common/thread_callbacks.hpp"

class AndroidThreadCallbacks: public ThreadCallbacks {
 public:
  AndroidThreadCallbacks(JNIEnv *jniEnv, jobject callbacks);
  void onThreadStarted() const override;
  void onIterationComplete(int iteration) const override;
  void onThreadFinished() const override;
 private:
  AndroidThreadCallbacks(JNIEnv *jniEnv,
                         jobject callbacks,
                         jclass callbacksClass);
  JNIEnv *const jniEnv;
  const jobject callbacks;
  const jmethodID onThreadStartedMethodID;
  const jmethodID onIterationCompleteMethodID;
  const jmethodID onThreadFinishedMethodID;
};

#endif // MYAPP_ANDROID_THREAD_CALLBACKS_HPP
