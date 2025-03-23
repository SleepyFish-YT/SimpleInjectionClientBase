// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_ITEM_H
#define SIMPLECLIENTBASE_ITEM_H

#include "../../SdkmClass.h"

struct Item : SdkmClass {

    Item();
    Item(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

};

#endif //SIMPLECLIENTBASE_ITEM_H