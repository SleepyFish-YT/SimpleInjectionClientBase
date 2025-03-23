// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "JavaList.h"
#include "../../utils/Java.h"
#include "../../utils/Mapper.h"

JavaList::JavaList(jobject instance) {
    this->clazz = Mapper::classes["javalist"];
    this->inst = instance;
}

jclass JavaList::getClazz() {
    return this->clazz;
}

jobject JavaList::getInst() {
    return this->inst;
}

jobjectArray JavaList::toArray() {
    if (this->isNull())
        return nullptr;

    return (jobjectArray) Java::env->CallObjectMethod(this->inst, Mapper::methods["list_toarray"]);
}