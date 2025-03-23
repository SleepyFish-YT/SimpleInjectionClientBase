// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "World.h"
#include "../../../utils/Mapper.h"
#include "../../java/JavaList.h"

World::World() {
    this->clazz = Mapper::classes["world"];
    this->inst = nullptr;
}

World::World(jobject inst) {
    this->clazz = Mapper::classes["world"];
    this->inst = inst;
}

jclass World::getClazz() {
    return this->clazz;
}

jobject World::getInst() {
    return this->inst;
}

std::vector<EntityPlayer> World::getPlayers() const {

    jobject playerEntitiesObj = Java::env->GetObjectField(this->inst, Mapper::fields["world_playerentities"]);
    auto playerEntitiesList = JavaList(playerEntitiesObj);

    jobjectArray playerEntities = playerEntitiesList.toArray();
    const int size = Java::env->GetArrayLength(playerEntities);
    std::vector<EntityPlayer> finalList;

    // start with index 1 because i don't want to get myself / thePlayer
    for (int index = 1; index < size; index++) {
        jobject obj_player = Java::env->GetObjectArrayElement(playerEntities, index);
        if (obj_player == nullptr)
            continue;

        auto player = EntityPlayer(obj_player);
        if (!player.isNull())
            finalList.push_back(player);
    }

    Java::env->DeleteLocalRef(playerEntities);
    Java::env->DeleteLocalRef(playerEntitiesObj);

    return finalList;
}
