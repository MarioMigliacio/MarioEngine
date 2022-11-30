#include "mepch.h"
#include "Application.h"

#include "MarioEngine/Events/ApplicationEvent.h"
#include "MarioEngine/Events/KeyEvent.h"
#include "MarioEngine/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace MarioEngine {

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(0, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

}