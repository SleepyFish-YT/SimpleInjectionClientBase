// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_VALUESETTING_H
#define SIMPLECLIENTBASE_VALUESETTING_H

#include "../Setting.h"

class ValueSetting : public Setting {

public:
    float val, min, max;

    ValueSetting(const char* name, float val, float min, float max) : Setting(name, 1) {
        this->val = val;
        this->min = min;
        this->max = max;
    }

};

#endif //SIMPLECLIENTBASE_VALUESETTING_H