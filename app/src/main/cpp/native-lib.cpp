#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_remember_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    return env->NewStringUTF("Hello from C++");
}