// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_VEC4_H
#define SIMPLECLIENTBASE_VEC4_H

struct Vec4 {

    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;

    Vec4 operator + (const Vec4& val) const {
        return Vec4 (x + val.x, y + val.y, z + val.z, w + val.w);
    }

    Vec4 operator - (const Vec4& val) const {
        return Vec4 (x - val.x, y - val.y, z - val.z, w - val.w);
    }

    Vec4 operator * (const float& val) const {
        return Vec4 (x * val, y * val, z * val, w * val);
    }

};

#endif //SIMPLECLIENTBASE_VEC4_H
