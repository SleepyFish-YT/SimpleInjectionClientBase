// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include "Module_Client.h"
#include "../../interface/Interface.h"
#include "../../../Client.h"

Module_Client::Module_Client() : Module("client", "manage the client settings") {

    this->addSetting(Module_Client::detach);
    this->addSetting(Module_Client::background);
    this->addSetting(Module_Client::clientColor);

}

void Module_Client::onGuiTick() {
    Interface::background = Module_Client::background->value;

    ImVec4 *style = ImGui::GetStyle().Colors;

    const ImColor col = Module_Client::clientColor->value;

    const float darkenVal1 = 0.5f;
    const float darkenVal2 = 0.2f;
    const ImColor col1 = ImColor(col.Value.x * darkenVal1, col.Value.y * darkenVal1, col.Value.z * darkenVal1, col.Value.w);
    const ImColor col2 = ImColor(col.Value.x * darkenVal2, col.Value.y * darkenVal2, col.Value.z * darkenVal2, col.Value.w);

    style[ImGuiCol_Border] = col;
    style[ImGuiCol_Text] = col;
    style[ImGuiCol_Button] = col2;
    style[ImGuiCol_CheckMark] = col2;
    style[ImGuiCol_Button] = col1;
    style[ImGuiCol_ButtonActive] = col2;
    style[ImGuiCol_ButtonHovered] = col1;
    style[ImGuiCol_FrameBg] = col1;
    style[ImGuiCol_FrameBgActive] = col1;
    style[ImGuiCol_FrameBgHovered] = col1;

    if (Module_Client::detach->value) {
        Interface::isGuiOpen = false;
        Interface::guiBind = 0;
        Client::inst->running = false;
        Module_Client::detach->value = false;
    }
}