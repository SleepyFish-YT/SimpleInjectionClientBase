// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "ActiveRenderInfo.h"
#include "../../../utils/Mapper.h"
#include "../../java/FloatBuffer.h"

ActiveRenderInfo::ActiveRenderInfo() {
    this->clazz = Mapper::classes["activerenderinfo"];
    this->inst = nullptr;
}

jclass ActiveRenderInfo::getClazz() {
    return this->clazz;
}

jobject ActiveRenderInfo::getInst() {
    return this->inst;
}

Matrix ActiveRenderInfo::getProjectionMatrix() const {
    jobject projection = Java::env->GetStaticObjectField(this->clazz, Mapper::fields["activerenderinfo_projection"]);
    Matrix m = FloatBuffer(projection).getMatrix();
    Java::env->DeleteLocalRef(projection);
    return m;
}

Matrix ActiveRenderInfo::getModelViewMatrix() const {
    jobject modelView = Java::env->GetStaticObjectField(this->clazz, Mapper::fields["activerenderinfo_modelview"]);
    Matrix m = FloatBuffer(modelView).getMatrix();
    Java::env->DeleteLocalRef(modelView);
    return m;
}