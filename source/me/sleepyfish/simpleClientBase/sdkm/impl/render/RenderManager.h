// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_RENDERMANAGER_H
#define SIMPLECLIENTBASE_RENDERMANAGER_H

#include "../../SdkmClass.h"
#include "../../../utils/unit/Vec3.h"

struct RenderManager : SdkmClass {

    RenderManager();
    RenderManager(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    Vec3 getRenderPosition() const;

};

#endif //SIMPLECLIENTBASE_RENDERMANAGER_H