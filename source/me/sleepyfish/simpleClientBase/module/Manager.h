// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef AUTOCLICKER_MANAGER_H
#define AUTOCLICKER_MANAGER_H

#include <vector>
#include "Module.h"
#include "impl/Auto_Clicker.h"
#include "impl/Player_Esp.h"
#include "impl/Text_Gui.h"
#include "impl/Module_Client.h"

class Manager {
private:
    std::vector<Module*> *modules;

public:
    Manager() {
        this->modules = new std::vector<Module*>;
    }

    std::vector<Module*> *getModules() const {
        return this->modules;
    }

    void setup() {
        this->modules->push_back(new Auto_Clicker());
        this->modules->push_back(new Player_Esp());
        this->modules->push_back(new Text_Gui());
        this->modules->push_back(new Module_Client());
    }

    void cleanup() {
    }

    void tick() {
        for (Module *module : *this->modules) {
            if (module->isEnabled())
                module->onTick();
        }
    }

    Module *getModuleByName(const char *string) {
        for (Module *module : *this->modules) {
            if (strcmp(module->getName(), string) == 0)
                return module;
        }

        return nullptr;
    }

};

#endif //AUTOCLICKER_MANAGER_H