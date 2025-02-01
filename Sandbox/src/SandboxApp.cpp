#include <SolidEngine.hpp>
#include <iostream>
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"
#include "ApplicationEvent.hpp"
#include "Log.hpp"

class SandboxApp : public SolidEngine::Application
{
public:
    SandboxApp()
    {
    }

    ~SandboxApp()
    {
    }

    void Run() override
    {
        std::cout << "Run SandboxApp\n";
		SolidEngine::KeyPressedEvent e(2, 5);
		SolidEngine::KeyReleasedEvent e2(2);
		SOLID_TRACE(e.ToString());
		SOLID_TRACE(e2.ToString());
        
		SolidEngine::MouseMovedEvent e3(150, 250);
		SolidEngine::MouseButtonPressedEvent e4(1);
		SOLID_TRACE(e3.ToString());
		SOLID_TRACE(e4.ToString());

        SolidEngine::WindowResizeEvent e5(1080, 1980);
        SolidEngine::WindowCloseEvent e6;
		SOLID_TRACE(e5.ToString());
		SOLID_TRACE(e6.ToString());

        SolidEngine::AppTickEvent e7;
        SolidEngine::AppUpdateEvent e8;
		SOLID_TRACE(e7.ToString());
		SOLID_TRACE(e8.ToString());
    }
};

// The client will defined their own CreateApplication
SolidEngine::Application* SolidEngine::CreateApplication()
{
    std::cout << "Create new Sandbox\n";
    return new SandboxApp();
}