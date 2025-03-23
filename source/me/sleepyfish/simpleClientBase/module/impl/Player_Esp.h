// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_PLAYER_ESP_H
#define SIMPLECLIENTBASE_PLAYER_ESP_H

#include "../Module.h"
#include "../../utils/unit/Matrix.h"
#include "../../utils/unit/Vec3.h"
#include "../setting/impl/BoolSetting.h"
#include "../../../../../../libraries/imgui/imgui.h"

class Player_Esp : public Module {

public:
    Player_Esp();

    void updateEnabled() override;
    void onTick() override;

    static void render(ImVec2 screenSize);

    static inline BoolSetting* invisOnly = new BoolSetting("only invisible players", false);

    static inline Matrix modelView;
    static inline Matrix projection;

    struct Data {
        std::vector<Vec3> boxVec;
        float health;
    };

    static inline std::vector<Data*>* renderData;

};

#endif //SIMPLECLIENTBASE_PLAYER_ESP_H