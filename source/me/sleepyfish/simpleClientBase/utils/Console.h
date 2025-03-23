// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_CONSOLE_H
#define SIMPLECLIENTBASE_CONSOLE_H

#include <cstdio>
#include "Windows.h"
#include "ClientUtils.h"

class Console {
public:
    static inline FILE* out = nullptr;
    static inline HWND consoleWindow = nullptr;

    static void setup() {
        AllocConsole();
        SetConsoleTitleA(ClientUtils::CLIENT_TITLE);
        consoleWindow = GetConsoleWindow();
        freopen_s(&out, "CONOUT$", "w", stdout);
    }

    static void cleanup() {
        ShowWindow(consoleWindow, SW_HIDE);
        clearerr_s(out);
        FreeConsole();
    }

    static void log(const char *log) {
        printf("  %s\n", log);
    }

    static void logA(const char *log, ...) {
        va_list args;
        va_start(args, log);
        printf("  ");
        vprintf(log, args);
        va_end(args);
    }

    static void log(){
        printf("\n");
    }

};

#endif //SIMPLECLIENTBASE_CONSOLE_H