#include <MarioEngine.h>

class ExampleLayer : public MarioEngine::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        // this is very obnoxious, but serves to demonstrate that layer is responsive.
        MARIOENGINE_CLIENT_INFO("ExampleLayer::Update");
    }

    void OnEvent(MarioEngine::Event& event) override
    {
        MARIOENGINE_CLIENT_TRACE("{0}", event);
    }

};

class Sandbox : public MarioEngine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

MarioEngine::Application* MarioEngine::CreateApplication()
{
    return new Sandbox();
}