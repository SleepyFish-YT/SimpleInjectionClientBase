// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_SETTING_H
#define SIMPLECLIENTBASE_SETTING_H

class Setting {
private:
    const char* name;
    int type;

public:
    Setting(const char* name, const int type) {
        this->name = name;
        this->type = type;
    }

    const char* getName() {
        return this->name;
    }

    int getType() const {
        return this->type;
    }

};

#endif //SIMPLECLIENTBASE_SETTING_H