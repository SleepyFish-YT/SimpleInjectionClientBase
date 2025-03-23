// Created by SleepyFish on 20-3-2025 for the SimpleInjectionClientBase project

#include "Text_Gui.h"
#include "../../interface/Interface.h"
#include "../../../Client.h"

Text_Gui::Text_Gui() : Module("text gui", "renders a list of all your enabled modules") {

    this->addSetting(this->resetPosition);

    this->enabled = true;

}

void Text_Gui::updateEnabled() {
    Interface::renderTextGui = this->enabled;
}

void Text_Gui::render() {
    if (Text_Gui::resetPosition->value) {
        ImGui::SetWindowPos({0, 0});
        Text_Gui::resetPosition->value = false;
    }

    const ImColor32 col = ImColor(Interface::clientColor);
    const bool sortModuleNameLengthInverted = ImGui::GetWindowPos().x > (ImGui::GetIO().DisplaySize.x / 2);

    float y = 10;

    ImGui::PushFont(Interface::fonts["sfuibold28"]);
        ImGui::SetOffset({10, y});
        ImGui::Text(ClientUtils::CLIENT_TITLE, col);
        float winSizeX = ImGui::GetFont()->CalcTextSizeAbyss(ClientUtils::CLIENT_TITLE).x;
    ImGui::PopFont();

    y += 30;
    float i = 0;

    ImGui::PushFont(Interface::fonts["sfuiregular24"]);
    {
        ImFont *font = ImGui::GetFont();
        for (Module *mod: *Client::inst->manager->getModules()) {
            if (mod->isEnabled()) {
                const char *name = mod->getName();

                if (!sortModuleNameLengthInverted) {
                    ImGui::SetOffset({10, y + (i * 20)});
                    ImGui::Text(name, col);
                } else {
                    ImGui::SetOffset({winSizeX - font->CalcTextSizeAbyss(name).x + 10, y + (i * 20)});
                    ImGui::Text(name, col);
                }

                i++;
            }
        }
    }
    ImGui::PopFont();

}