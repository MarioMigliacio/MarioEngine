#pragma once

#ifdef MARIOENGINE_PLATFORM_WINDOWS

extern MarioEngine::Application* MarioEngine::CreateApplication();

int main(int argc, char** argv)
{
    MarioEngine::Log::Init();
    MARIOENGINE_CORE_WARN("Mario Engine up and running!");
    int num = 10;
    MARIOENGINE_CLIENT_INFO("Hello mario app! Variable: {0}", num);

    auto app = MarioEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif