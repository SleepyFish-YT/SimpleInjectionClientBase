// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "Auto_Clicker.h"
#include "../../../Client.h"
#include "../../utils/MinecraftUtils.h"

Auto_Clicker::Auto_Clicker() : Module("auto clicker", "automatically clicks the mouse when holding down") {

    this->addSetting(this->weaponOnly);
    this->addSetting(this->breakBlocks);
    this->addSetting(this->ignoreInventory);
    this->addSetting(this->minCps);
    this->addSetting(this->maxCps);

    this->clickUtilsLeft = new ClickUtils(0);

    this->enabled = true;

}

void Auto_Clicker::onTick() {
    if (this->weaponOnly->value) {
        if (!MinecraftUtils::holdingWeapon())
            return;
    }

    if (this->ignoreInventory->value) {
        if (!Client::inst->minecraft->hasIngameFocus())
            return;
    }

    if (Utils::holdingMouseLeft()) {
        bool t = false;
        if (this->breakBlocks->value) {
            MovingObjectPosition obj = Client::inst->minecraft->getObjectMouseOver();
            if (!obj.isNull()) {
                if (obj.isTypeOfBlock())
                    t = true;
            }
        }

        this->clickUtilsLeft->update(this->minCps->val, this->maxCps->val, t);
    }
}