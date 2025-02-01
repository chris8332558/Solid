#pragma once

#include "Event.hpp"
#include <sstream>

namespace SolidEngine {

    // Base class for KeyPressedEvent and KeyReleasedEvent
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }
        virtual int GetCategoryFlags() const override {
            return EventCategory::EventCategoryInput | EventCategory::EventCategoryKeyboard;
        }

    protected:
        KeyEvent(int keyCode) : m_KeyCode(keyCode) {}
        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keyCode, int repeatCount) 
            : KeyEvent(keyCode), m_RepeatCount(repeatCount) {} 
        
        inline int GetRepeatCount() const { return m_RepeatCount; }

        static EventType GetStaticType() { return EventType::KeyPressed; }
        virtual EventType GetEventType() const override { return GetStaticType(); } 
        virtual const char* GetName() const override { return "KeyPressed"; } 

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

    private:
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

        static EventType GetStaticType() { return EventType::KeyReleased; }
        virtual EventType GetEventType() const override { return GetStaticType(); } 
        virtual const char* GetName() const override { return "KeyReleased"; } 

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }
    };
}