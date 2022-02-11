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

void threadBody() {
    print("HECMEN here");
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_remember_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject mainActivity) {
    callMethod(env, mainActivity);

    std::thread thr(threadBody);
    thr.detach();

    return env->NewStringUTF("Hello from C++");
}