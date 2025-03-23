// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_INTERFACE_H
#define SIMPLECLIENTBASE_INTERFACE_H

#include "Windows.h"
#include "../../../../../libraries/imgui/imgui.h"
#include "map"
#include "../module/Module.h"

typedef void(*callback)();

class Interface {
public:

    // setup rendering stuff
    static inline HWND handleWindow;
    static inline HDC handleDeviceContext;
    static inline HGLRC originalGLContext;
    static inline HGLRC menuGLContext;
    static void setupImgui();

    // basic interface stuff
    static inline bool isGuiOpen;
    static inline int guiBind;
    static inline bool background;
    static std::map<const char*, ImFont*> fonts;
    static std::map<const char*, ImFont*> images;

    static inline ImVec4 clientColor = {220.0f / 255.0f, 220.0f / 255.0f, 220.0f / 255.0f, 1.0f};
    static inline ImVec4 backgroundColor = {19.0f / 255.0f, 19.0f / 255.0f, 19.0f / 255.0f, 0.9f};

    static inline Module *selectedModule;
    static inline bool renderTextGui = false;
    static inline bool renderPlayerEsp = false;

    static void setup();
    static void cleanup();
    static void onGuiToggle();
    static void onGuiRender();

};

#endif //SIMPLECLIENTBASE_INTERFACE_H