// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "CTimer.h"
#include "../../../utils/Mapper.h"

CTimer::CTimer() {
    this->clazz = Mapper::classes["timer"];
    this->inst = nullptr;
}

CTimer::CTimer(jobject inst) {
    this->clazz = Mapper::classes["timer"];
    this->inst = inst;
}

jclass CTimer::getClazz() {
    return this->clazz;
}

jobject CTimer::getInst() {
    return this->inst;
}

jfloat CTimer::getPartialTicks() const {
    return Java::env->GetFloatField(this->inst, Mapper::fields["timer_partialticks"]);
}