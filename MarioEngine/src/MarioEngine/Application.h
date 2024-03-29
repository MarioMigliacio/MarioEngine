#pragma once

#include "Core.h"
#include "Window.h"
#include "MarioEngine/LayerStack.h"

namespace MarioEngine {

    // this macro serves to simplify bind calls. Bind calls are function wrappers where a callback method 
    // is generated using the args (in this case, this, and placeholders as whatever we pass in).
    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    class MARIOENGINE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

    private:
        bool OnWindowClosed(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}