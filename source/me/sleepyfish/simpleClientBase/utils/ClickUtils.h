// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_AUTOCLICKER_CLICKUTILS_H
#define SIMPLECLIENTBASE_AUTOCLICKER_CLICKUTILS_H

#include "Utils.h"
#include "Windows.h"
#include "chrono"

class ClickUtils {

private:
    POINT pos_cursor;
    int keyCode;
    int keyStateDown;
    int keyStateFinalUp;
    LPARAM param;

    float nextCps = 1;
    long long lastClickTime = 0;

public:
    ClickUtils(int keyCode) :
        keyCode(keyCode),
        keyStateDown(0),
        keyStateFinalUp(0)
    {
        this->init();
    }

    void init() {
        GetCursorPos(&this->pos_cursor);
        this->param = MAKELPARAM(this->pos_cursor.x, this->pos_cursor.y);

        if (this->keyCode == 0) {
            this->keyStateDown = WM_LBUTTONDOWN;
            this->keyStateFinalUp = WM_LBUTTONUP;
            return;
        }

        if (this->keyCode == 1) {
            this->keyStateDown = WM_RBUTTONDOWN;
            this->keyStateFinalUp = WM_RBUTTONUP;
            return;
        }
    }

    void update(float min, float max, bool stop = false) {
        if (this->nextCps == 0)
            return;

        long long milliLeft = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        if (this->lastClickTime == 0L)
            this->lastClickTime = milliLeft;

        if ((milliLeft - this->lastClickTime) < (1000L / (long long) this->nextCps))
            return;

        const int code = this->keyCode + 1;

        if (!stop) {
            const HWND &handleWindow = GetForegroundWindow();
            SendMessageA(handleWindow, this->keyStateDown, code, this->param);
            SendMessageA(handleWindow, this->keyStateFinalUp, code, this->param);
        }

        this->lastClickTime = milliLeft;
        this->nextCps = Utils::randomFloat(min, max);
    }

};

#endif //SIMPLECLIENTBASE_AUTOCLICKER_CLICKUTILS_H