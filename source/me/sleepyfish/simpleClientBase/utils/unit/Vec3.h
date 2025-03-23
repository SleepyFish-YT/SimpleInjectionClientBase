// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_VEC3_H
#define SIMPLECLIENTBASE_VEC3_H

#include <complex>

struct Vec3 {

    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    Vec3 operator + (const Vec3& val) const {
        return Vec3 (x + val.x, y + val.y, z + val.z);
    }

    Vec3 operator - (const Vec3& val) const {
        return Vec3 (x - val.x, y - val.y, z - val.z);
    }

    Vec3 operator * (const float& val) const {
        return Vec3 (x * val, y * val, z * val);
    }

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    float distance(const Vec3& val) const {
        return (*this - val).length();
    }

};

#endif //SIMPLECLIENTBASE_VEC3_H