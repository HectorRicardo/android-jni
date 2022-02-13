//
// Created by hecto on 1/4/2022.
//

#ifndef MYAPP_ANDROID_BRIDGE_H
#define MYAPP_ANDROID_BRIDGE_H

#include <jni.h>
#include "common/PlatformBridge.hpp"

class AndroidBridge : public PlatformBridge {
 public:
  AndroidBridge(JNIEnv *jniEnv, jobject threadHandler);
  void onThreadStarted() const override;
 private:
  JNIEnv *jniEnv;
  jobject threadHandler;
  jmethodID onThreadStartedMethodID;
};

#endif // MYAPP_ANDROID_BRIDGE_H
