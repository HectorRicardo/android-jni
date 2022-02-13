//
// Created by hecto on 1/4/2022.
//

#include <jni.h>
#include "AndroidBridge.hpp"

AndroidBridge::AndroidBridge(JNIEnv *jniEnv, jobject threadHandler)
    : jniEnv(jniEnv),
      threadHandler(threadHandler),
      methodToBeCalledFromJNI(
          jniEnv->GetMethodID(jniEnv->GetObjectClass(threadHandler),
                              "onThreadStart",
                              "()V")) {}

void AndroidBridge::callThreadStartedMethod() const {
  jniEnv->CallVoidMethod(threadHandler, methodToBeCalledFromJNI);
}
