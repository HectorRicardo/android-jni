//
// Created by hecto on 1/4/2022.
//

#include <jni.h>
#include "AndroidBridge.hpp"

AndroidBridge::AndroidBridge(JNIEnv *jniEnv, jobject mainActivity)
    : jniEnv(jniEnv),
      mainActivity(mainActivity),
      methodToBeCalledFromJNI(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(mainActivity),
                              "methodToBeCalledFromJNI",
                              "()V")) {}

void AndroidBridge::callThreadStartedMethod() const {
  jniEnv->CallVoidMethod(mainActivity, methodToBeCalledFromJNI);
}
