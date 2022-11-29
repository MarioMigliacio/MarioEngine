#include "Application.h"

#include "MarioEngine/Events/ApplicationEvent.h"
#include "MarioEngine/Log.h"

namespace MarioEngine {

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(2000, 1000);

        if (e.IsInCategory(EventCategoryApplication))
        {
            MARIOENGINE_CORE_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            MARIOENGINE_CORE_TRACE(e);
        }

        while (true);
    }

}