// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "MovingObjectPosition.h"
#include "../../../utils/Mapper.h"

MovingObjectPosition::MovingObjectPosition() {
    this->clazz = Mapper::classes["movingobjectposition"];
    this->inst = nullptr;
}

MovingObjectPosition::MovingObjectPosition(jobject inst) {
    this->clazz = Mapper::classes["movingobjectposition"];
    this->inst = inst;
}

jclass MovingObjectPosition::getClazz() {
    return this->clazz;
}

jobject MovingObjectPosition::getInst() {
    return this->inst;
}

jbool MovingObjectPosition::isTypeOfBlock() const {
    return strcmp(getCurrentType(), "BLOCK") == 0;
}

const char *MovingObjectPosition::getCurrentType() const {
    jobject typeOfHitInstance = Java::env->GetObjectField(this->inst, Mapper::fields["movingobjectposition_typeofhit"]);

    if (typeOfHitInstance == nullptr)
        return "false";

    static jclass typeOfHitClass = Java::env->GetObjectClass(typeOfHitInstance);
    if (typeOfHitClass == nullptr)
        return "false";

    static jmethodID toString = Java::findMethod(typeOfHitClass, "toString", "()Ljava/lang/String;");
    if (toString == nullptr)
        return "false";

    auto string = (jstring) Java::env->CallObjectMethod(typeOfHitInstance, toString);
    if (string == nullptr)
        return "false";

    const char *rawString = Java::env->GetStringUTFChars(string, 0);
    const char *returnVal = rawString;

    Java::env->ReleaseStringUTFChars(string, rawString);

    return returnVal;
}