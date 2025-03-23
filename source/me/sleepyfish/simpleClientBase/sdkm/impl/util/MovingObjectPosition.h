// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_MOVINGOBJECTPOSITION_H
#define SIMPLECLIENTBASE_MOVINGOBJECTPOSITION_H

#include "../../SdkmClass.h"

struct MovingObjectPosition : SdkmClass {

    MovingObjectPosition();
    MovingObjectPosition(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    jbool isTypeOfBlock() const;
    const char *getCurrentType() const;

};


#endif //SIMPLECLIENTBASE_MOVINGOBJECTPOSITION_H
