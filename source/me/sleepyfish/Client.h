// Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

#ifndef SIMPLECLIENTBASE_CLIENT_H
#define SIMPLECLIENTBASE_CLIENT_H

#include "ClientMain.h"

class Client {
public:
    static inline ClientMain* inst = new ClientMain();

};

#endif //SIMPLECLIENTBASE_CLIENT_H