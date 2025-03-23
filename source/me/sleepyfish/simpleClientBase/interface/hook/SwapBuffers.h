// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#include "../../../../../../libraries/imgui/imgui_impl_opengl2.h"
#include "../../../../../../libraries/imgui/imgui_impl_win32.h"
#include "../../../../../../libraries/minhook/minhook.h"
#include "../../../../../../assets/fonts/sfuiregular.h"
#include "../../../../../../assets/fonts/sfuibold.h"
#include "../../module/impl/Text_Gui.h"
#include "../../utils/ClientUtils.h"
#include "../Interface.h"
#include "Keypress.h"
#include <gl/gl.h>
#include <mutex>

std::once_flag setupFlag;

typedef bool(__stdcall *wgl_SwapBuffers)(HDC hdc);
wgl_SwapBuffers originalWglSwapBuffers;

bool __stdcall hook_wglSwapBuffers(_In_ HDC hdc) {
    Interface::handleDeviceContext = hdc;
    Interface::handleWindow = WindowFromDC(hdc);
    Interface::originalGLContext = wglGetCurrentContext();

    std::call_once(setupFlag, [&]() {
        hook_onInput();
        Interface::setupImgui();

        ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = Interface::backgroundColor;
    });

    glDepthFunc(GL_LEQUAL);
    wglMakeCurrent(Interface::handleDeviceContext, Interface::menuGLContext);

    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplWin32_NewFrame();
    {
        ImGui::NewFrame();
        {
            if (Interface::renderPlayerEsp) {
                {
                    const ImVec2 size = ImGui::GetIO().DisplaySize;
                    ImGui::SetNextWindowPos({0, 0});
                    ImGui::SetNextWindowSize(size);
                    ImGui::Begin("po", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNav);
                    {
                        Player_Esp::render(size);
                    }
                    ImGui::End();
                }
            }

            if (Interface::renderTextGui) {
                {
                    ImGui::SetNextWindowSize({260, 220});
                    ImGui::Begin("o", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNav);
                    {
                        Text_Gui::render();
                    }
                    ImGui::End();
                }
            }

            if (Interface::isGuiOpen) {
                ImGui::PushFont(Interface::fonts["sfuiregular20"]);
                {
                    ImGui::SetNextWindowSize({480, 312});
                    ImGui::Begin("i", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
                    {
                        const ImVec2 windowPos = ImGui::GetWindowPos();
                        const ImVec2 windowSize = ImGui::GetWindowSize();
                        const float endX = windowPos.x + windowSize.x - 10;

                        ImDrawList* drawList = ImGui::GetForegroundDrawList();

                        const ImVec2 topLeft = windowPos;
                        const ImVec2 bottomRight = ImVec2(endX, windowPos.y + windowSize.y);
                        const ImColor col = ImColor(Interface::clientColor);

                        ImGui::GetBackgroundDrawList()->AddRectFilled(topLeft, bottomRight, ImColor(Interface::backgroundColor));

                        drawList->AddRect(topLeft, bottomRight, col);
                        drawList->AddRect({windowPos.x, windowPos.y + 32}, {endX, windowPos.y + 32}, col);
                        drawList->AddTextSleepy(ClientUtils::CLIENT_TITLE, {windowPos.x + 10, windowPos.y + 7}, col);

                        Interface::onGuiRender();
                    }
                    ImGui::End();
                }
                ImGui::PopFont();
            }
        }
        ImGui::EndFrame();
        ImGui::Render();
    }
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    // i think this is used to bypass obs and discord screen shares
    wglMakeCurrent(Interface::handleDeviceContext, Interface::originalGLContext);
    return originalWglSwapBuffers(hdc);
}

void hook_renderSwapBuffers() {
    auto wglSwapBuffers = (LPVOID) GetProcAddress(GetModuleHandle("opengl32.dll"), "wglSwapBuffers");
    MH_CreateHook(wglSwapBuffers, (LPVOID)hook_wglSwapBuffers, (LPVOID*)&originalWglSwapBuffers);
    MH_EnableHook(wglSwapBuffers);
}

void unhook_renderSwapBuffers() {
    ImGui_ImplOpenGL2_DestroyFontsTexture();
    ImGui_ImplOpenGL2_DestroyDeviceObjects();
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplWin32_Shutdown();
    MH_DisableHook(MH_ALL_HOOKS);
    MH_RemoveHook(MH_ALL_HOOKS);
}

void Interface::setupImgui() {
    Interface::menuGLContext = wglCreateContext(Interface::handleDeviceContext);
    wglMakeCurrent(Interface::handleDeviceContext, Interface::menuGLContext);

    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        GLint m_viewport[4];
        glGetIntegerv(GL_VIEWPORT, m_viewport);
        glOrtho(0, m_viewport[2], m_viewport[3], 0, 1, -1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glClearColor(0, 0, 0, 0);
    }

    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    {
        const ImGuiIO &io = ImGui::GetIO();
        io.Fonts->AddFontDefault();

        Interface::fonts["sfuiregular20"] = io.Fonts->AddFontFromMemoryTTF(sfuiregular, sizeof(sfuiregular), 20.0f);
        Interface::fonts["sfuiregular24"] = io.Fonts->AddFontFromMemoryTTF(sfuiregular, sizeof(sfuiregular), 24.0f);
        Interface::fonts["sfuibold28"] = io.Fonts->AddFontFromMemoryTTF(sfuibold, sizeof(sfuibold), 28.0f);
    }

    ImGui_ImplWin32_Init(Interface::handleWindow);
    ImGui_ImplOpenGL2_Init();
}