// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_SDKMCLASS_H
#define SIMPLECLIENTBASE_SDKMCLASS_H

#include "../../../../../libraries/jni/jni.h"

struct SdkmClass {

    jobject inst {};
    jclass clazz {};

    virtual jobject getInst() = 0;
    virtual jclass getClazz() = 0;

    bool isNull() const {
        return this->clazz == nullptr || this->inst == nullptr;
    }

    bool isObjectNull() const {
        return this->inst == nullptr;
    }

    bool isClassNull() const {
        return this->clazz == nullptr;
    }

};

#endif //SIMPLECLIENTBASE_SDKMCLASS_H