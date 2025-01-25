#include <SolidEngine.hpp>
#include <iostream>

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
    }
};

// The client will defined their own CreateApplication
SolidEngine::Application* SolidEngine::CreateApplication()
{
    std::cout << "Create new Sandbox\n";
    return new SandboxApp();
}