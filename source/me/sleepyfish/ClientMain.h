// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_CLIENTMAIN_H
#define SIMPLECLIENTBASE_CLIENTMAIN_H

#include "simpleClientBase/utils/Console.h"
#include "simpleClientBase/sdkm/impl/Minecraft.h"
#include "simpleClientBase/module/Manager.h"
#include "simpleClientBase/utils/Java.h"
#include "../../../libraries/minhook/minhook.h"
#include "simpleClientBase/interface/Interface.h"
#include "simpleClientBase/utils/Mapper.h"

class ClientMain {
public:

    bool running = false;
    Java* java = new Java();

    Console* console = new Console();
    Manager* manager = new Manager();
    Minecraft* minecraft {};

    void setup() {
        Console::setup();
        this->running = !this->java->setup();

        if (this->running) {
            Mapper::setup();
            this->manager->setup();
            Interface::renderTextGui = manager->getModuleByName("text gui")->enabled;
            this->minecraft = new Minecraft();
            MH_Initialize();
            Interface::setup();
        }
    }

    void mainLoop() {
        // main loop
        while (this->running) {
            if (Utils::hasIngameFocus()) {

                // main event loop call
                if (!Interface::isGuiOpen) {
                    if (!this->minecraft->isNull() && !this->minecraft->getPlayer().isNull()) {
                        this->manager->tick();
                    }
                }
            }

            // sleep for 0.20 seconds
            Sleep(20L);
        }
    }

    void cleanup() {
        if (!this->running) {
            printf("cleaned up1\n");
            Sleep(1000);

            Interface::cleanup();
            printf("cleaned up2\n");
            Sleep(1000);

            MH_Uninitialize();
            printf("cleaned up3\n");
            Sleep(1000);

            this->manager->cleanup();
            printf("cleaned up4\n");
            Sleep(1000);

            Mapper::cleanup();
            printf("cleaned up5\n");
            Sleep(1000);

            this->java->cleanup();
            printf("cleaned up6\n");
            Sleep(1000);

            printf("cleaned up7\n");
            Console::cleanup();
            Sleep(1000);
        }
    }

};

#endif //SIMPLECLIENTBASE_CLIENTMAIN_H