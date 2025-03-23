// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#include <vector>
#include "FloatBuffer.h"
#include "../../utils/Java.h"
#include "../../utils/Mapper.h"

FloatBuffer::FloatBuffer(jobject obj) {
    this->clazz = Mapper::classes["floatbuffer"];
    this->inst = obj;
}

jclass FloatBuffer::getClazz() {
    return this->clazz;
}

jobject FloatBuffer::getInst() {
    return this->inst;
}

Matrix FloatBuffer::getMatrix() {
    std::vector<jfloat> arr;

    for (int i = 0; i < 16; i++) {
        arr.push_back(Java::env->CallFloatMethod(this->inst, Mapper::methods["floatbuffer_get"], i));
    }

    Matrix m {};

    m.m00 = arr[0];
    m.m01 = arr[1];
    m.m02 = arr[2];
    m.m03 = arr[3];

    m.m10 = arr[4];
    m.m11 = arr[5];
    m.m12 = arr[6];
    m.m13 = arr[7];

    m.m20 = arr[8];
    m.m21 = arr[9];
    m.m22 = arr[10];
    m.m23 = arr[11];

    m.m30 = arr[12];
    m.m31 = arr[13];
    m.m32 = arr[14];
    m.m33 = arr[15];

    return m;
}