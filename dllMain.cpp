// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "Windows.h"
#include "source/me/sleepyfish/Client.h"

void Init(HMODULE mod) {
    Client::inst->setup();
    Client::inst->mainLoop();
    Client::inst->cleanup();
    FreeLibrary(mod);
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {

    // checks if the dll action is attach
    if (dwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);

        // create thread for the main loop passing argument hModule to the init function
        HANDLE hThread = CreateThread (
            nullptr, 0, (LPTHREAD_START_ROUTINE) (Init), hModule, 0, nullptr
        );

        // close the thread
        if (hThread != nullptr)
            CloseHandle(hThread);
    }

    return true;
}