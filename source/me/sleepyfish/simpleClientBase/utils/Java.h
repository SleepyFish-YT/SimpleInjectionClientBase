// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_JAVA_H
#define SIMPLECLIENTBASE_JAVA_H

#include "../../../../../libraries/jni/jni.h"
#include "Utils.h"
#include "Console.h"

class Java {
private:
    JavaVM* vm;
    static inline jobject classLoader = nullptr;
    static inline jmethodID mid_findClass = nullptr;

public:
    static inline JNIEnv* env = nullptr;

    bool setup() {
        jsize count = 0;
            if (JNI_GetCreatedJavaVMs(&this->vm, 1, &count) != JNI_OK || count == 0)
                return true;

        jint res = this->vm->GetEnv((void **) &Java::env, JNI_VERSION_1_8);
        if (res == JNI_EDETACHED)
            res = this->vm->AttachCurrentThreadAsDaemon((void **) &Java::env, nullptr);

        if (res != JNI_OK)
            return true;

        if (Java::env == nullptr) {
            this->vm->DestroyJavaVM();
            return true;
        }

        if (Java::env->FindClass("com/moonsworth/lunar/genesis/Genesis") == nullptr) {
            Utils::messageBox("This client is only compatible with Lunar Client 1.8.9");
            return true;
        }


        { // get minecraft classloader

            jclass c_Map = Java::env->FindClass("java/util/Map");
            jclass c_Set = Java::env->FindClass("java/util/Set");
            jclass c_Thread = Java::env->FindClass("java/lang/Thread");
            jclass c_ClassLoader = Java::env->FindClass("java/lang/ClassLoader");

            jmethodID mid_getAllStackTraces = Java::env->GetStaticMethodID(c_Thread, "getAllStackTraces", "()Ljava/util/Map;");
            jmethodID mid_keySet = Java::env->GetMethodID(c_Map, "keySet", "()Ljava/util/Set;");
            jmethodID mid_toArray = Java::env->GetMethodID(c_Set, "toArray", "()[Ljava/lang/Object;");
            jmethodID mid_getContextClassLoader = Java::env->GetMethodID(c_Thread, "getContextClassLoader", "()Ljava/lang/ClassLoader;");

            jobject obj_stackTracesMap = Java::env->CallStaticObjectMethod(c_Thread, mid_getAllStackTraces);
            jobject obj_threadsSet = Java::env->CallObjectMethod(obj_stackTracesMap, mid_keySet);

            auto threads = (jobjectArray) Java::env->CallObjectMethod(obj_threadsSet, mid_toArray);
            jint szThreads = Java::env->GetArrayLength(threads);

            mid_findClass = Java::env->GetMethodID(c_ClassLoader, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
            jstring className = Java::env->NewStringUTF("net.minecraft.client.Minecraft");

            for (int i = 0; i < szThreads; i++) {
                jobject thread = Java::env->GetObjectArrayElement(threads, i);
                jobject classLoaderObj = Java::env->CallObjectMethod(thread, mid_getContextClassLoader);

                if (classLoaderObj != nullptr) {
                    jobject minecraftClass = Java::env->CallObjectMethod(classLoaderObj, mid_findClass, className);

                    if (minecraftClass != nullptr) {
                        classLoader = classLoaderObj;
                        Console::log("Java: Got Minecraft classloader");
                        Java::env->DeleteLocalRef(minecraftClass);
                        break;
                    }
                }

                Java::env->DeleteLocalRef(classLoaderObj);
                Java::env->DeleteLocalRef(thread);
            }

        } // get minecraft classloader

        count = 0;
        return false;
    }

    void cleanup() {
        this->vm->DetachCurrentThread();
    }

    static jclass findLunarClass(const char* name) {
        jstring className = Java::env->NewStringUTF(name);
        jobject findClass = Java::env->CallObjectMethod(classLoader, mid_findClass, className);
        Java::env->DeleteLocalRef(className);

        if (findClass)
            return (jclass) findClass;

        return nullptr;
    }

    static jfieldID findField(jclass clazz, const char *name, const char *sig, bool statik = false) {
        if (!statik) {
            return Java::env->GetFieldID(clazz, name, sig);
        } else {
            return Java::env->GetStaticFieldID(clazz, name, sig);
        }
    }

    static jmethodID findMethod(jclass clazz, const char *name, const char *sig, bool statik = false) {
        if (!statik) {
            return Java::env->GetMethodID(clazz, name, sig);
        } else {
            return Java::env->GetStaticMethodID(clazz, name, sig);
        }
    }

    static bool sameObject(jobject one, jobject two) {
        return Java::env->IsSameObject(one, two);
    }

    static jbool instanceOf(jobject inst, jclass clazz) {
        if (inst == nullptr || clazz == nullptr) return false;
        return Java::env->IsInstanceOf(inst, clazz);
    }

};

#endif //SIMPLECLIENTBASE_JAVA_H