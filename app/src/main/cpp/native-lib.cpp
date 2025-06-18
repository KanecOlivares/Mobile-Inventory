#include <jni.h>

extern "C"
JNIEXPORT jstring JNICALL
Kotlin_com_example_MobileInventory_MainActivity_stringFromCpp(JNIEnv* env, jobject) {
    return env->NewStringUTF("Hello from C++!");
}
