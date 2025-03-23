// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "Entity.h"
#include "../../../utils/Mapper.h"

Entity::Entity() {
    this->clazz = Mapper::classes["entity"];
    this->inst = nullptr;
}

Entity::Entity(jobject inst) {
    this->clazz = Mapper::classes["entity"];
    this->inst = inst;
}

jclass Entity::getClazz() {
    return this->clazz;
}

jobject Entity::getInst() {
    return this->inst;
}

jbool Entity::isAlive() const {
    return !Java::env->GetBooleanField(this->inst, Mapper::fields["entity_isdead"]);
}

jbool Entity::isInvisible() const {
    return Java::env->CallBooleanMethod(this->inst, Mapper::methods["entity_isinvisible"]);
}

Vec3 Entity::getPosition() const {
    return {
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["entity_x"]),
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["entity_y"]),
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["entity_z"])
    };
}

Vec3 Entity::getLastPosition() const {
    return {
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["entity_lasttickposx"]),
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["entity_lasttickposy"]),
        (jfloat) Java::env->GetDoubleField(this->inst, Mapper::fields["entity_lasttickposz"])
    };
}