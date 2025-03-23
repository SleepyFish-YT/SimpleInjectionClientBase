// Created by SleepyFish on 20-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_TEXT_GUI_H
#define SIMPLECLIENTBASE_TEXT_GUI_H

#include "../Module.h"
#include "../setting/impl/BoolSetting.h"

class Text_Gui : public Module {

public:
    Text_Gui();

    void updateEnabled() override;

    static void render();

    static inline BoolSetting* resetPosition = new BoolSetting("reset position", false);

};

#endif //SIMPLECLIENTBASE_TEXT_GUI_H