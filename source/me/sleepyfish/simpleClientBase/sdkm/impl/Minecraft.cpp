// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "Minecraft.h"
#include "../../utils/Java.h"
#include "../../utils/Mapper.h"

Minecraft::Minecraft() {
    this->clazz = Mapper::classes["minecraft"];
    this->inst = Java::env->GetStaticObjectField(this->clazz, Mapper::fields["minecraft_theminecraft"]);
}

jclass Minecraft::getClazz() {
    return this->clazz;
}

jobject Minecraft::getInst() {
    return this->inst;
}

EntityPlayerSP Minecraft::getPlayer() const {
    return {
        Java::env->GetObjectField(this->inst, Mapper::fields["minecraft_theplayer"])
    };
}

WorldClient Minecraft::getWorld() const {
    return {
        Java::env->GetObjectField(this->inst, Mapper::fields["minecraft_theworld"])
    };
}

MovingObjectPosition Minecraft::getObjectMouseOver() const {
    return {
        Java::env->GetObjectField(this->inst, Mapper::fields["minecraft_objectmouseover"])
    };
}

RenderManager Minecraft::getRenderManager() {
    return {
        Java::env->GetObjectField(this->inst, Mapper::fields["minecraft_rendermanager"])
    };
}

CTimer Minecraft::getTimer() const {
    return {
        Java::env->GetObjectField(this->inst, Mapper::fields["minecraft_timer"])
    };
}

jbool Minecraft::hasIngameFocus() const {
    return Java::env->GetBooleanField(this->inst, Mapper::fields["minecraft_hasingamefocus"]);
}