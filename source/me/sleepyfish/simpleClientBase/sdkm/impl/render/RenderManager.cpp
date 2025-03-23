// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "RenderManager.h"
#include "../../../utils/Mapper.h"

RenderManager::RenderManager() {
    this->clazz = Mapper::classes["rendermanager"];
    this->inst = nullptr;
}

RenderManager::RenderManager(jobject inst) {
    this->clazz = Mapper::classes["rendermanager"];
    this->inst = inst;
}

jclass RenderManager::getClazz() {
    return this->clazz;
}

jobject RenderManager::getInst() {
    return this->inst;
}

Vec3 RenderManager::getRenderPosition() const {
    return {
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["rendermanager_renderposx"]),
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["rendermanager_renderposy"]),
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["rendermanager_renderposz"])
    };
}