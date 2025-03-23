//
// Created by Luca on 3/19/2025.
//

#ifndef SIMPLECLIENTBASE_MINECRAFTUTILS_H
#define SIMPLECLIENTBASE_MINECRAFTUTILS_H

#include "Mapper.h"
#include "../../Client.h"
#include "../sdkm/impl/item/Item.h"

class MinecraftUtils {
public:

    static bool holdingWeapon() {
        Item item = Client::inst->minecraft->getPlayer().getHeldItem().getItem();
        if (!item.isNull())
            return Java::instanceOf(item.inst, Mapper::classes["itemsword"]) || Java::instanceOf(item.inst, Mapper::classes["itemaxe"]);

        return false;
    }

};

#endif //SIMPLECLIENTBASE_MINECRAFTUTILS_H