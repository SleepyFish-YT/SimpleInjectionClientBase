// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_CTIMER_H
#define SIMPLECLIENTBASE_CTIMER_H

#include "../../SdkmClass.h"

struct CTimer : SdkmClass {

    CTimer();
    CTimer(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    jfloat getPartialTicks() const;

};

#endif //SIMPLECLIENTBASE_CTIMER_H