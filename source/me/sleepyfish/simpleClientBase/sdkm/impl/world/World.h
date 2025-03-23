// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_WORLD_H
#define SIMPLECLIENTBASE_WORLD_H

#include <vector>
#include "../../SdkmClass.h"
#include "../entity/EntityPlayer.h"

struct World : SdkmClass {

    World();
    World(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    std::vector<EntityPlayer> getPlayers() const;

};

#endif //SIMPLECLIENTBASE_WORLD_H