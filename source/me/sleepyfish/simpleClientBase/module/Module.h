// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_MODULE_H
#define SIMPLECLIENTBASE_MODULE_H

#include <vector>
#include "setting/Setting.h"

class Module {
private:
    const char *name;
    const char *description;
    std::vector<Setting*> *settings;

public:
    bool enabled;

    Module(const char* name, const char* description) {
        this->name = name;
        this->description = description;
        this->settings = new std::vector<Setting*>();

        this->enabled = false;
    }

    bool isEnabled() const {
        return this->enabled;
    }

    const char *getName() const {
        return this->name;
    }

    const char *getDescription() const {
        return this->description;
    }

    const std::vector<Setting*> *getSettings() const {
        return this->settings;
    }

    void addSetting(Setting* setting) {
        this->settings->push_back(setting);
    }

    virtual void updateEnabled() {};
    virtual void onTick() {};

};

#endif //SIMPLECLIENTBASE_MODULE_H