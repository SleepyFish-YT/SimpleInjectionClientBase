// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_ENTITYLIVINGBASE_H
#define SIMPLECLIENTBASE_ENTITYLIVINGBASE_H

#include "Entity.h"

struct EntityLivingBase : Entity {

    EntityLivingBase();
    EntityLivingBase(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    jfloat getHealth() const;

};

#endif //SIMPLECLIENTBASE_ENTITYLIVINGBASE_H