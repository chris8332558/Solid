#pragma once

#include <string>

#define BIT(x) (1 << x)
namespace SolidEngine
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    // Each EventType can be in multiple Categories
    enum EventCategory
    {
        None=0,
        EventCategoryApplication   = BIT(1),
        EventCategoryInput         = BIT(2),
        EventCategoryKeyboard      = BIT(3),
        EventCategoryMouse         = BIT(4),
        EventCategoryMouseButton   = BIT(5)
    };

    class Event
    {
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); } // For debug and spdlog logging 

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
        // Not sure why we use T here instead of just use Event
        template<typename T>
        using EventFn = std::function<bool(T&)>; 
    public:
        EventDispatcher(Event& event) : m_Event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            } 
            return false;
        }

    private:
        Event& m_Event;
    };
}
