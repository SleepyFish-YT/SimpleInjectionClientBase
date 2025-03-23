// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_ENTITY_H
#define SIMPLECLIENTBASE_ENTITY_H

#include "../../SdkmClass.h"
#include "../../../utils/unit/Vec3.h"

struct Entity : SdkmClass {

    Entity();
    Entity(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    jbool isAlive() const;
    jbool isInvisible() const;
    Vec3 getPosition() const;
    Vec3 getLastPosition() const;

};

#endif //SIMPLECLIENTBASE_ENTITY_H