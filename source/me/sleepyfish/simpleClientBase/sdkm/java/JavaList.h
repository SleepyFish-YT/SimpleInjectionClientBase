// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_JAVALIST_H
#define SIMPLECLIENTBASE_JAVALIST_H

#include "../SdkmClass.h"

struct JavaList : SdkmClass {

    JavaList();
    JavaList(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    jobjectArray toArray();

};

#endif //SIMPLECLIENTBASE_JAVALIST_H