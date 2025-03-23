// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_MAPPER_H
#define SIMPLECLIENTBASE_MAPPER_H

#include <map>
#include "../../../../../libraries/jni/jni.h"
#include "Java.h"
#include "Console.h"

class Mapper {
private:

public:
    static inline std::map<const char*, jclass> classes = {};
    static inline std::map<const char*, jmethodID> methods = {};
    static inline std::map<const char*, jfieldID> fields = {};

    static void setup() {
        classes = std::map<const char*, jclass>();
        methods = std::map<const char*, jmethodID>();
        fields = std::map<const char*, jfieldID>();

        // classes
        {
            classes["floatbuffer"] = Java::env->FindClass("java/nio/FloatBuffer");
            classes["javalist"] = Java::env->FindClass("java/util/List");

            classes["minecraft"] = Java::findLunarClass("net.minecraft.client.Minecraft");
            classes["entitylivingbase"] = Java::findLunarClass("net.minecraft.entity.EntityLivingBase");
            classes["entity"] = Java::findLunarClass("net.minecraft.entity.Entity");
            classes["entityplayer"] = Java::findLunarClass("net.minecraft.entity.player.EntityPlayer");
            classes["entityplayersp"] = Java::findLunarClass("net.minecraft.client.entity.EntityPlayerSP");
            classes["world"] = Java::findLunarClass("net.minecraft.world.World");
            classes["worldclient"] = Java::findLunarClass("net.minecraft.client.multiplayer.WorldClient");
            classes["item"] = Java::findLunarClass("net.minecraft.item.Item");
            classes["itemstack"] = Java::findLunarClass("net.minecraft.item.ItemStack");
            classes["itemsword"] = Java::findLunarClass("net.minecraft.item.ItemSword");
            classes["itemaxe"] = Java::findLunarClass("net.minecraft.item.ItemAxe");
            classes["movingobjectposition"] = Java::findLunarClass("net.minecraft.util.MovingObjectPosition");
            classes["timer"] = Java::findLunarClass("net.minecraft.util.Timer");
            classes["rendermanager"] = Java::findLunarClass("net.minecraft.client.renderer.entity.RenderManager");
            classes["activerenderinfo"] = Java::findLunarClass("net.minecraft.client.renderer.ActiveRenderInfo");
        }

        // fields
        {
            methods["list_toarray"] = Java::findMethod(classes["javalist"], "toArray", "()[Ljava/lang/Object;");

            fields["minecraft_theminecraft"] = Java::findField(classes["minecraft"], "theMinecraft", "Lnet/minecraft/client/Minecraft;", true);
            fields["minecraft_hasingamefocus"] = Java::findField(classes["minecraft"], "inGameHasFocus", "Z");
            fields["minecraft_theworld"] = Java::findField(classes["minecraft"], "theWorld", "Lnet/minecraft/client/multiplayer/WorldClient;");
            fields["minecraft_theplayer"] = Java::findField(classes["minecraft"], "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;");
            fields["minecraft_objectmouseover"] = Java::findField(classes["minecraft"], "objectMouseOver", "Lnet/minecraft/util/MovingObjectPosition;");
            fields["minecraft_timer"] = Java::findField(classes["minecraft"], "timer", "Lnet/minecraft/util/Timer;");
            fields["minecraft_rendermanager"] = Java::findField(classes["minecraft"], "renderManager", "Lnet/minecraft/client/renderer/entity/RenderManager;");
            fields["movingobjectposition_typeofhit"] = Java::findField(classes["movingobjectposition"], "typeOfHit", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;");
            fields["timer_partialticks"] = Java::findField(classes["timer"], "renderPartialTicks", "F");
            fields["rendermanager_renderposx"] = Java::findField(classes["rendermanager"], "renderPosX", "D");
            fields["rendermanager_renderposy"] = Java::findField(classes["rendermanager"], "renderPosY", "D");
            fields["rendermanager_renderposz"] = Java::findField(classes["rendermanager"], "renderPosZ", "D");
            fields["entity_isdead"] = Java::findField(classes["entity"], "isDead", "Z");
            fields["entity_x"] = Java::findField(classes["entity"], "posX", "D");
            fields["entity_y"] = Java::findField(classes["entity"], "posY", "D");
            fields["entity_z"] = Java::findField(classes["entity"], "posZ", "D");
            fields["entity_lasttickposx"] = Java::findField(classes["entity"], "lastTickPosX", "D");
            fields["entity_lasttickposy"] = Java::findField(classes["entity"], "lastTickPosY", "D");
            fields["entity_lasttickposz"] = Java::findField(classes["entity"], "lastTickPosZ", "D");
            fields["activerenderinfo_projection"] = Java::findField(classes["activerenderinfo"], "PROJECTION", "Ljava/nio/FloatBuffer;", true);
            fields["activerenderinfo_modelview"] = Java::findField(classes["activerenderinfo"], "MODELVIEW", "Ljava/nio/FloatBuffer;", true);
            fields["world_playerentities"] = Java::findField(classes["world"], "playerEntities", "Ljava/util/List;");
        }

        // methods
        {
            methods["floatbuffer_get"] = Java::findMethod(classes["floatbuffer"], "get", "(I)F");
            methods["entityplayer_getcurrentequippeditem"] = Java::findMethod(classes["entityplayer"], "getCurrentEquippedItem", "()Lnet/minecraft/item/ItemStack;");
            methods["itemstack_getitem"] = Java::findMethod(classes["itemstack"], "getItem", "()Lnet/minecraft/item/Item;");
            methods["entity_isinvisible"] = Java::findMethod(classes["entity"], "isInvisible", "()Z");
            methods["entitylivingbase_gethealth"] = Java::findMethod(classes["entitylivingbase"], "getHealth", "()F");
        }

        checkForInvalidMappings();
    }

    static void cleanup() {
        classes.clear();
        methods.clear();
        fields.clear();
    }

    static void checkForInvalidMappings() {
        for (auto& it : classes) {
            if (it.second == nullptr)
                Console::logA("Invalid class mapping: %s\n", it.first);
        }

        for (auto& it : methods) {
            if (it.second == nullptr)
                Console::logA("Invalid method mapping: %s\n", it.first);
        }

        for (auto& it : fields) {
            if (it.second == nullptr)
                Console::logA("Invalid field mapping: %s\n", it.first);
        }
    }

};

#endif //SIMPLECLIENTBASE_MAPPER_H