// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_MINECRAFT_H
#define SIMPLECLIENTBASE_MINECRAFT_H

#include "../SdkmClass.h"
#include "entity/EntityPlayerSP.h"
#include "util/MovingObjectPosition.h"
#include "world/WorldClient.h"
#include "util/CTimer.h"
#include "render/RenderManager.h"
#include "render/ActiveRenderInfo.h"

struct Minecraft : SdkmClass {

    Minecraft();

    jclass getClazz() override;
    jobject getInst() override;

    EntityPlayerSP getPlayer() const;
    WorldClient getWorld() const;
    MovingObjectPosition getObjectMouseOver() const;
    RenderManager getRenderManager();
    CTimer getTimer() const;
    jbool hasIngameFocus() const;

    ActiveRenderInfo* activeRenderInfo;

};

#endif //SIMPLECLIENTBASE_MINECRAFT_H