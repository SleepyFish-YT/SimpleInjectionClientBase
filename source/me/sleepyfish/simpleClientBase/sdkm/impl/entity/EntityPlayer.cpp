// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "EntityPlayer.h"
#include "../../../utils/Mapper.h"

EntityPlayer::EntityPlayer() : EntityLivingBase() {
    this->clazz = Mapper::classes["entityplayer"];
    this->inst = nullptr;
}

EntityPlayer::EntityPlayer(jobject inst) : EntityLivingBase(inst) {
    this->clazz = Mapper::classes["entityplayer"];
    this->inst = inst;
}

jclass EntityPlayer::getClazz() {
    return this->clazz;
}

jobject EntityPlayer::getInst() {
    return this->inst;
}

ItemStack EntityPlayer::getHeldItem() const {
    return {
        Java::env->CallObjectMethod(this->inst, Mapper::methods["entityplayer_getcurrentequippeditem"])
    };
}