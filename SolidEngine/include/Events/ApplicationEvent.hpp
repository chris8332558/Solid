#pragma once

#include "Event.hpp"
#include <sstream>

namespace SolidEngine
{
    class WindowCloseEvent : public Event
    {
    public:
        static EventType GetStaticType() { return EventType::WindowClose; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "WindowCloseEvent"; }
        virtual int GetCategoryFlags() const override {
            return EventCategory::EventCategoryApplication; 
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowCloseEvent";
            return ss.str();
        }
    };

    class WindowResizeEvent : public Event
    {
    public: 
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        static EventType GetStaticType() { return EventType::WindowResize; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "WindowResizeEvent"; }
        virtual int GetCategoryFlags() const override {
            return EventCategory::EventCategoryApplication; 
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

    private:
        unsigned int m_Width, m_Height;
    };

    class AppTickEvent : public Event
    {
    public:
        static EventType GetStaticType() { return EventType::AppTick; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "AppTickEvent"; }
        virtual int GetCategoryFlags() const override {
            return EventCategory::EventCategoryApplication; 
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "AppTickEvent";
            return ss.str();
        }
    };

    class AppUpdateEvent : public Event
    {
    public:
        static EventType GetStaticType() { return EventType::AppUpdate; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "AppUpdateEvent"; }
        virtual int GetCategoryFlags() const override {
            return EventCategory::EventCategoryApplication; 
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "AppUpdateEvent";
            return ss.str();
        }
    };
    
    class AppRenderEvent : public Event
    {
    public:
        static EventType GetStaticType() { return EventType::AppRender; }
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "AppRenderEvent"; }
        virtual int GetCategoryFlags() const override {
            return EventCategory::EventCategoryApplication; 
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "AppRenderEvent";
            return ss.str();
        }
    };
}