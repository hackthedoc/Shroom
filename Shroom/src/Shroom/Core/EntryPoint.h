#pragma once

#include "Shroom/Core/Application.h"

extern  Shroom::Application* CreateApplication();

int main() {
    Shroom::Log::Init();

    auto app = CreateApplication();

    app->Run();

    delete app;

    return 0;
}
