#include <MarioEngine.h>

class Sandbox : public MarioEngine::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

MarioEngine::Application* MarioEngine::CreateApplication()
{
    return new Sandbox();
}