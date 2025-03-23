// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_AUTOCLICKER_UTILS_H
#define SIMPLECLIENTBASE_AUTOCLICKER_UTILS_H

#include "Windows.h"
#include "ClientUtils.h"
#include <random>

class Utils {
public:

    // random number generator for floats (used for randomizing clicks)
    static float randomFloat(float min, float max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(min, max);
        return dis(gen);
    }

    // check if ur holding the right mouse button
    static bool holdingMouseRight() {
        return GetAsyncKeyState(VK_RBUTTON) & 0x8000;
    }

    // check if ur holding the left mouse button
    static bool holdingMouseLeft() {
        return GetAsyncKeyState(VK_LBUTTON) & 0x8000;
    }

    // check if ur foreground window is from the class LWJGL
    static bool hasIngameFocus() {
        return GetForegroundWindow() == FindWindowA("LWJGL", nullptr);
    }

    // shows a windows message box with the given title and text and flags
    static inline void messageBox(const char* text, const int flags = MB_OK | MB_ICONINFORMATION) {
        MessageBoxA(nullptr, text, ClientUtils::CLIENT_TITLE, flags);
    }

    // gets the current process path name
    static const std::string getCurrentProcessPathName() {
        char name[MAX_PATH];
        GetModuleFileNameA(nullptr, name, MAX_PATH);
        return name;
    }

};

#endif //SIMPLECLIENTBASE_AUTOCLICKER_UTILS_H