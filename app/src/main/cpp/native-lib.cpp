#include <jni.h>
#include <string>
#include <thread>
#include "print.hpp"

void callMethod(JNIEnv* env, jobject mainActivity) {
    jclass mainActivityClass = env->GetObjectClass(mainActivity);
    jmethodID
        j_method = env->GetMethodID(mainActivityClass, "onThreadStart", "()V");
    env->CallVoidMethod(mainActivity, j_method);
}

void threadBody(JavaVM *javaVM, jobject mainActivityGlobal) {
    JNIEnv *env;
    javaVM->AttachCurrentThread(&env, nullptr);
    callMethod(env, mainActivityGlobal);
    env->DeleteGlobalRef(mainActivityGlobal);
    javaVM->DetachCurrentThread();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_remember_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject mainActivity) {
    callMethod(env, mainActivity);

    JavaVM *javaVM;
    env->GetJavaVM(&javaVM);

    jobject mainActivityGlobal = env->NewGlobalRef(mainActivity);
    std::thread thr(threadBody, javaVM, mainActivityGlobal);
    thr.detach();

    return env->NewStringUTF("Hello from C++");
}