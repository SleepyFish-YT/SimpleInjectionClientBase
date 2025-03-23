// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_FLOATBUFFER_H
#define SIMPLECLIENTBASE_FLOATBUFFER_H

#include "../SdkmClass.h"
#include "../../utils/unit/Matrix.h"

struct FloatBuffer : SdkmClass {
    
    FloatBuffer(jobject obj);

    jclass getClazz() override;
    jobject getInst() override;

    Matrix getMatrix();
    
};

#endif //SIMPLECLIENTBASE_FLOATBUFFER_H