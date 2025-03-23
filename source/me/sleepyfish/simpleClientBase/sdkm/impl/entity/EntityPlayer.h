// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_ENTITYPLAYER_H
#define SIMPLECLIENTBASE_ENTITYPLAYER_H

#include "EntityLivingBase.h"
#include "../item/ItemStack.h"

struct EntityPlayer : EntityLivingBase {

    EntityPlayer();
    EntityPlayer(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    ItemStack getHeldItem() const;

};

#endif //SIMPLECLIENTBASE_ENTITYPLAYER_H