// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "WorldClient.h"
#include "../../../utils/Mapper.h"

WorldClient::WorldClient() : World() {
    this->clazz = Mapper::classes["worldclient"];
    this->inst = nullptr;
}

WorldClient::WorldClient(jobject inst) : World(inst) {
    this->clazz = Mapper::classes["worldclient"];
    this->inst = inst;
}

jclass WorldClient::getClazz() {
    return this->clazz;
}

jobject WorldClient::getInst() {
    return this->inst;
}