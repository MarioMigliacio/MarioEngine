#pragma once

#include "MarioEngine/Core.h"

#include <functional>

namespace MarioEngine {

    // Events in MarioEngine are currently blocking, meaning when an event occurs it
    // immediately gets dispatched and must be dealt with right away. 
    // For the future, a better strategy might be to buffer events in an event queue
    // and process them during the "event" part of the update stage.

    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication        = BIT(0),
        EventCategoryInput              = BIT(1),
        EventCategoryKeyboard           = BIT(2),
        EventCategoryMouse              = BIT(3),
        EventCategoryMouseButton        = BIT(4)
    };

    // using these two macros in conbination provides clean syntax for the interface of the inheriting event classes.
    // for example: much simpler to type:
    // EVENT_CLASS_TYPE(MouseMoved)
    // EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    // than it is to type:
    // static EventType GetStaticType() { return EventType::MouseMoved; }
    // virtual EventType GetEventType() const override { return GetStaticType(); }
    // virtual const char* GetName() const override { return "MouseMoved"; }
    // virtual int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }

    // this macro is a little nasty, but ## is the token-pasting operator, it is used to merge the type passed in into the enum type 
    // we have defined. While the single # operator is the stringify operator, it wraps type argument with quotes to form a string from type.
    // this macro is designed to prevent having to type all 3 of these member methods in all the derived Event sub classifications.
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
        virtual EventType GetEventType() const override { return GetStaticType(); }\
        virtual const char* GetName() const override { return #type; }

    // macro for the implementation of the pure virtual GetCategoryFlags function.
    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class MARIOENGINE_API Event
    {
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }
        
        inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event)
            : m_Event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                // syntax is a little gnarly, but it means to take the reference of m_Event. Cast it to a T Pointer, 
                // then dereference that pointer and call for the result of that function. The event could be of any type,
                // as long is it implements the Event interface.
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.ToString(); }
}