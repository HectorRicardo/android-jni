//
// Created by hecto on 1/4/2022.
//

#ifndef MYAPP_ANDROID_THREAD_CALLBACKS_HPP
#define MYAPP_ANDROID_THREAD_CALLBACKS_HPP

#include <jni.h>
#include "common/thread_callbacks.hpp"

class Android_Thread_Callbacks : public Thread_Callbacks {
 public:
  Android_Thread_Callbacks(JNIEnv *jniEnv, jobject threadCallbacks);
  void onThreadStarted() const override;
  void onIterationComplete(int iteration) const override;
  void onThreadFinished() const override;
 private:
  JNIEnv *jniEnv;
  jobject threadCallbacks;
  jmethodID onThreadStartedMethodID;
  jmethodID onIterationCompleteMethodID;
  jmethodID onThreadFinishedMethodID;
};

#endif // MYAPP_ANDROID_THREAD_CALLBACKS_HPP
