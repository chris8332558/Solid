#pragma once

#include "Event.hpp"
#include <sstream>

namespace SolidEngine
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float mouseX, float mouseY) 
            : m_MouseX(mouseX), m_MouseY(mouseY) {}

        inline float GetMouseX() { return m_MouseX; }
        inline float GetMouseY() { return m_MouseY; }

        static EventType StaticType() { return EventType::MouseMoved; }
        virtual EventType GetEventType() const override { return StaticType(); }
        virtual const char* GetName() const override { return "MouseMovedEvent"; }
        virtual int GetCategoryFlags() const override { 
            return EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse;
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        } 

    private:
        float m_MouseX, m_MouseY;
    };


    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float offsetX, float offsetY)
            : m_xOffset(offsetX), m_yOffset(offsetY) {}

        inline float GetOffsetX() { return m_xOffset; }
        inline float GetOffsetY() { return m_yOffset; }

        static EventType GetStaticType() { return EventType::MouseScrolled; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "MouseScrolledEvent"; }
        virtual int GetCategoryFlags() const override { 
            return EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse;
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
            return ss.str();
        } 

    private:
        float m_xOffset, m_yOffset;
    };


    class MouseButtonEvent : public Event 
    {
    public:
        inline int GetButton() { return m_Button; }
        virtual int GetCategoryFlags() const override {
            return EventCategory::EventCategoryInput | EventCategory::EventCategoryMouseButton;
        }

    protected:
        MouseButtonEvent(int button) : m_Button(button) {}
        int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
        
        static EventType GetStaticType() { return EventType::MouseButtonPressed; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "MouseButtonPressedEvent"; }
        virtual std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        static EventType GetStaticType() { return EventType::MouseButtonReleased; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "MouseButtonReleasedEvent"; }
        virtual std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }
    };
}