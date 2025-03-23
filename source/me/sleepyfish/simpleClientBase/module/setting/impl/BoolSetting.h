// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_BOOLSETTING_H
#define SIMPLECLIENTBASE_BOOLSETTING_H

#include "../Setting.h"

class BoolSetting : public Setting {
public:
    bool value;

    BoolSetting(const char* name, bool value) : Setting(name, 0) {
        this->value = value;
    }

};

#endif //SIMPLECLIENTBASE_BOOLSETTING_H