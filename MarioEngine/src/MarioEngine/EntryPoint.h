#pragma once

#ifdef MARIOENGINE_PLATFORM_WINDOWS

extern MarioEngine::Application* MarioEngine::CreateApplication();

int main(int argc, char** argv)
{
    MarioEngine::Log::Init();
    MARIOENGINE_CLIENT_INFO("Mario Engine is online.");

    auto app = MarioEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif