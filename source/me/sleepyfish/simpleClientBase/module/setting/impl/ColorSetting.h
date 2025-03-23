// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_COLORSETTING_H
#define SIMPLECLIENTBASE_COLORSETTING_H

#include "../Setting.h"
#include "../../../../../../../libraries/imgui/imgui.h"

class ColorSetting : public Setting {
public:
    ImColor value;

    ColorSetting(const char* name, ImColor value) : Setting(name, 2) {
        this->value = value;
    }

};

#endif //SIMPLECLIENTBASE_COLORSETTING_H