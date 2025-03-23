// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "EntityLivingBase.h"
#include "../../../utils/Mapper.h"

EntityLivingBase::EntityLivingBase() : Entity() {
    this->clazz = Mapper::classes["entitylivingbase"];
    this->inst = nullptr;
}

EntityLivingBase::EntityLivingBase(jobject inst) : Entity(inst) {
    this->clazz = Mapper::classes["entitylivingbase"];
    this->inst = inst;
}

jobject EntityLivingBase::getInst() {
    return this->inst;
}

jclass EntityLivingBase::getClazz() {
    return this->clazz;
}

jfloat EntityLivingBase::getHealth() const {
    return Java::env->CallFloatMethod(this->inst, Mapper::methods["entitylivingbase_gethealth"]);
}
