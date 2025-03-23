// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "Interface.h"
#include "hook/SwapBuffers.h"
#include "../module/Module.h"
#include "../../Client.h"

std::map<const char*, ImFont*> Interface::fonts;
std::map<const char*, ImFont*> Interface::images;

void Interface::setup() {
    Interface::isGuiOpen = false;
    Interface::guiBind = VK_DELETE;
    Interface::selectedModule = Client::inst->manager->getModules()->at(0);

    hook_renderSwapBuffers();
}

void Interface::cleanup() {
    Interface::isGuiOpen = false;
    Interface::guiBind = 0;

    unhook_renderSwapBuffers();
    unhook_onInput();

    wglMakeCurrent(Interface::handleDeviceContext, Interface::originalGLContext);
    wglDeleteContext(Interface::menuGLContext);

    ImGui::DestroyContext();
}

void Interface::onGuiToggle() {
    Interface::isGuiOpen = !Interface::isGuiOpen;
}

void Interface::onGuiRender() {
    Interface::clientColor = Module_Client::clientColor->value;

    Module_Client::onGuiTick();

    if (Interface::background) {
        const ImVec2 pos = {-4, -4};

        ImGui::SetNextWindowPos(pos);
        ImGui::SetNextWindowSize({ImGui::GetIO().DisplaySize.x + 8, ImGui::GetIO().DisplaySize.y + 8});

        ImGui::Begin("ba", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNav);
        {
            ImGui::GetWindowDrawList()->AddRectFilled(pos, ImGui::GetWindowSize(), ImColor(0.1f, 0.1f, 0.1f, 0.6f));
        }
        ImGui::End();
    }

    float y = 40;

    ImGui::SetOffset({10, y});

    for (Module *mod : *Client::inst->manager->getModules()) {
        if (ImGui::Button(mod->getName())) {
            Interface::selectedModule = mod;
        }

        ImGui::SameLine();
    }

    y += 30;

    if (Interface::selectedModule != nullptr) {
        ImGui::SetOffset({10, y});
        ImGui::Text(Interface::selectedModule->getDescription(), Interface::clientColor);

        y += 30;

        ImGui::SetOffset({10, y});
        if (ImGui::Checkbox("enabled", &Interface::selectedModule->enabled)) {
            Interface::selectedModule->updateEnabled();
        }

        y += 30;

        float i = 0;
        for (Setting *setting : *Interface::selectedModule->getSettings()) {
            if (setting->getType() == 0) {
                auto* s = static_cast<BoolSetting*>(setting);
                ImGui::SetOffset({10, y + (i * 30)});
                ImGui::Checkbox(setting->getName(), &s->value);
            } else if (setting->getType() == 1) {
                ValueSetting* s = static_cast<ValueSetting*>(setting);
                ImGui::SetOffset({10, y + (i * 30)});
                ImGui::DragFloat(setting->getName(), &s->val, 0.04f, s->min, s->max, "%.2f");
            } else if (setting->getType() == 2) {
                ColorSetting* s = static_cast<ColorSetting*>(setting);
                ImGui::SetOffset({10, y + (i * 30)});
                float color[4] = {s->value.Value.x, s->value.Value.y, s->value.Value.z, s->value.Value.w};
                ImGui::ColorPickerSmellon(setting->getName(), color, true, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoRightClick);
                s->value.Value.x = color[0];
                s->value.Value.y = color[1];
                s->value.Value.z = color[2];
                s->value.Value.w = color[3];
            }

            i++;
        }
    }

}