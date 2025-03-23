// Created by SleepyFish on 22-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_ACTIVERENDERINFO_H
#define SIMPLECLIENTBASE_ACTIVERENDERINFO_H

#include "../../SdkmClass.h"
#include "../../../utils/unit/Matrix.h"

struct ActiveRenderInfo : SdkmClass {

    ActiveRenderInfo();

    jclass getClazz() override;
    jobject getInst() override;

    Matrix getProjectionMatrix() const;
    Matrix getModelViewMatrix() const;

};

#endif //SIMPLECLIENTBASE_ACTIVERENDERINFO_H