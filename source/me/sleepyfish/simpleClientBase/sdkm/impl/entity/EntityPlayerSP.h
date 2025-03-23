// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_ENTITYPLAYERSP_H
#define SIMPLECLIENTBASE_ENTITYPLAYERSP_H

#include "EntityPlayer.h"

struct EntityPlayerSP : EntityPlayer {

    EntityPlayerSP();
    EntityPlayerSP(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

};

#endif //SIMPLECLIENTBASE_ENTITYPLAYERSP_H