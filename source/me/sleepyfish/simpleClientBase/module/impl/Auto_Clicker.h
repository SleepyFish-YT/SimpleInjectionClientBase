// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_AUTO_CLICKER_H
#define SIMPLECLIENTBASE_AUTO_CLICKER_H

#include "../Module.h"
#include "../../utils/ClickUtils.h"
#include "../setting/impl/ValueSetting.h"
#include "../setting/impl/BoolSetting.h"

class Auto_Clicker : public Module {

public:
    Auto_Clicker();

    void onTick() override;

    BoolSetting *weaponOnly = new BoolSetting("weapon only", true);
    BoolSetting *breakBlocks = new BoolSetting("break blocks", true);
    BoolSetting *ignoreInventory = new BoolSetting("ignore inventory", true);
    ValueSetting *minCps = new ValueSetting("min cps", 12.0f, 1.0f, 22.0f);
    ValueSetting *maxCps = new ValueSetting("max cps", 16.0f, 2.0f, 24.0f);

    ClickUtils *clickUtilsLeft {};

};

#endif //SIMPLECLIENTBASE_AUTO_CLICKER_H