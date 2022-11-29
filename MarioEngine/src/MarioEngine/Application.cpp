#include "mepch.h"
#include "Application.h"

#include "MarioEngine/Events/ApplicationEvent.h"
#include "MarioEngine/Events/KeyEvent.h"
#include "MarioEngine/Events/MouseEvent.h"
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
        int key = 'a';
        KeyPressedEvent ke(key, 2);
        MouseButtonPressedEvent me(1);

        if (e.IsInCategory(EventCategoryApplication))
        {
            MARIOENGINE_CORE_TRACE(e);
        }
        if (ke.IsInCategory(EventCategoryKeyboard))
        {
            MARIOENGINE_CORE_TRACE(ke);
        }
        if (me.IsInCategory(EventCategoryMouse))
        {
            MARIOENGINE_CORE_TRACE(me);
        }

        while (true);
    }

}