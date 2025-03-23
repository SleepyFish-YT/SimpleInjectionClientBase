// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "Item.h"
#include "../../../utils/Mapper.h"

Item::Item() {
    this->clazz = Mapper::classes["item"];
    this->inst = nullptr;
}

Item::Item(jobject inst) {
    this->clazz = Mapper::classes["item"];
    this->inst = inst;
}

jclass Item::getClazz() {
    return this->clazz;
}

jobject Item::getInst() {
    return this->inst;
}