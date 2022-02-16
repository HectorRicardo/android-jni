//
// Created by hecto on 1/4/2022.
//

#ifndef MYAPP_ANDROID_THREAD_EXECUTION_CALLBACKS_H
#define MYAPP_ANDROID_THREAD_EXECUTION_CALLBACKS_H

#include <jni.h>
#include "common/ThreadExecutionCallbacks.hpp"

class AndroidThreadExecutionCallbacks : public ThreadExecutionCallbacks {
 public:
  AndroidThreadExecutionCallbacks(JNIEnv *jniEnv, jobject threadCallbacks);
  void onThreadStarted() const override;
 private:
  JNIEnv *jniEnv;
  jobject threadCallbacks;
  jmethodID onThreadStartedMethodID;
};

#endif // MYAPP_ANDROID_THREAD_EXECUTION_CALLBACKS_H
