// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "EntityPlayerSP.h"
#include "../../../utils/Mapper.h"

EntityPlayerSP::EntityPlayerSP() : EntityPlayer() {
    this->clazz = Mapper::classes["entityplayersp"];
    this->inst = nullptr;
}

EntityPlayerSP::EntityPlayerSP(jobject inst) : EntityPlayer(inst) {
    this->clazz = Mapper::classes["entityplayersp"];
    this->inst = inst;
}

jclass EntityPlayerSP::getClazz() {
    return this->clazz;
}

jobject EntityPlayerSP::getInst() {
    return this->inst;
}