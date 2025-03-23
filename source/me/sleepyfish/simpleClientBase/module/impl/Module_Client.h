// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_MODULE_CLIENT_H
#define SIMPLECLIENTBASE_MODULE_CLIENT_H

#include "../Module.h"
#include "../setting/impl/ValueSetting.h"
#include "../setting/impl/BoolSetting.h"
#include "../setting/impl/ColorSetting.h"

class Module_Client : public Module {

public:
    Module_Client();

    static void onGuiTick();

    static inline BoolSetting *detach = new BoolSetting("detach", false);
    static inline BoolSetting *background = new BoolSetting("background", true);
    static inline ColorSetting *clientColor = new ColorSetting("client color", {220.0f / 255.0f, 220.0f / 255.0f, 220.0f / 255.0f, 1.0f});

};

#endif //SIMPLECLIENTBASE_MODULE_CLIENT_H