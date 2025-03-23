// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_ITEMSTACK_H
#define SIMPLECLIENTBASE_ITEMSTACK_H

#include "../../SdkmClass.h"
#include "Item.h"

struct ItemStack : SdkmClass {

    ItemStack();
    ItemStack(jobject inst);

    jclass getClazz() override;
    jobject getInst() override;

    Item getItem() const;

};

#endif //SIMPLECLIENTBASE_ITEMSTACK_H