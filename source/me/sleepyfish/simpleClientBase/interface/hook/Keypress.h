// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "../Interface.h"
#include "../../../../../../libraries/imgui/imgui.h"
#include "../../../Client.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef LRESULT(CALLBACK *template_WndProc)(HWND, UINT, WPARAM, LPARAM);

template_WndProc original_wndProc;

LRESULT CALLBACK hook_WndProc(HWND hwnd, UINT inputType, WPARAM inputKey, LPARAM lParam) {

    if (inputKey < 256) {
        if (!Interface::isGuiOpen) {
            if (inputKey == VK_BACK) {
                if (Client::inst->minecraft->hasIngameFocus()) {
                    Client::inst->running = false;
                    return CallWindowProcA(original_wndProc, hwnd, inputType, inputKey, lParam);
                }
            }
        }

        if (inputType == WM_KEYDOWN) {
            if (inputKey == Interface::guiBind) {
                Interface::onGuiToggle();
            }
        }
    }

    if (Interface::isGuiOpen) {
        ImGui_ImplWin32_WndProcHandler(hwnd, inputType, inputKey, lParam);
        return true;
    }

    return CallWindowProcA(original_wndProc, hwnd, inputType, inputKey, lParam);
}

void hook_onInput() {
    original_wndProc = (template_WndProc) SetWindowLongPtrA(Interface::handleWindow, GWLP_WNDPROC, (LONG_PTR) hook_WndProc);
}

void unhook_onInput() {
    SetWindowLongPtrA(Interface::handleWindow, GWLP_WNDPROC, (LONG_PTR) original_wndProc);
}