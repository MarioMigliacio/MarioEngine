#pragma once

#ifdef MARIOENGINE_PLATFORM_WINDOWS

extern MarioEngine::Application* MarioEngine::CreateApplication();

int main(int argc, char** argv)
{
    printf("MarioEngine up and running.\n");
    auto app = MarioEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif