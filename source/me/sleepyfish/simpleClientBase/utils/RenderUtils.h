// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_RENDERUTILS_H
#define SIMPLECLIENTBASE_RENDERUTILS_H

#include "unit/Vec4.h"
#include "unit/Vec3.h"
#include "unit/Matrix.h"
#include "unit/Vec2.h"

class RenderUtils {
public:

    static Vec4 multiply(Vec4 v, Matrix m) {
        return Vec4 {
            v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + v.w * m.m30,
            v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + v.w * m.m31,
            v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + v.w * m.m32,
            v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + v.w * m.m33
        };
    }

    static bool worldToScreen(Vec3 point, Matrix modelView, Matrix projection, ImVec2& size, Vec2& screenPos) {
        Vec4 csp = multiply ( multiply( Vec4 { point.x, point.y, point.z, 1.0F }, modelView), projection );

        Vec3 ndc {
                csp.x / csp.w,
                csp.y / csp.w,
                csp.z / csp.w
        };

        if (ndc.z > 1 && ndc.z < 1.15) {
            screenPos = Vec2 {
                ((ndc.x + 1.0f) / 2.0f) * size.x,
                ((1.0f - ndc.y) / 2.0f) * size.y,
            };

            return true;
        }

        return false;
    }

};

#endif //SIMPLECLIENTBASE_RENDERUTILS_H