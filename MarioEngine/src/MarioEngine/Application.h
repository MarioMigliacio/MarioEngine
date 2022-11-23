#pragma once

#include "Core.h"

namespace MarioEngine {

    class MARIOENGINE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}