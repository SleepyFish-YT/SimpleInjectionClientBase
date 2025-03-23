// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "ItemStack.h"
#include "../../../utils/Mapper.h"

ItemStack::ItemStack() {
    this->clazz = Mapper::classes["itemstack"];
    this->inst = nullptr;
}

ItemStack::ItemStack(jobject inst) {
    this->clazz = Mapper::classes["itemstack"];
    this->inst = inst;
}

jclass ItemStack::getClazz() {
    return this->clazz;
}

jobject ItemStack::getInst() {
    return this->inst;
}

Item ItemStack::getItem() const {
    return {
        Java::env->CallObjectMethod(this->inst, Mapper::methods["itemstack_getitem"])
    };
}