// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_WORLDCLIENT_H
#define SIMPLECLIENTBASE_WORLDCLIENT_H

#include "World.h"

struct WorldClient : World {

    WorldClient();
    WorldClient(jobject inst);

    jclass getClazz();
    jobject getInst();

};

#endif //SIMPLECLIENTBASE_WORLDCLIENT_H