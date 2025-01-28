#pragma once

//extern SolidEngine::Application* SolidEngine::CreateApplication();
int main(int argc, char **argv)
{
    SolidEngine::Log::Init();   
    SOLID_CORE_WARN("Initialized Log!");
    int a = 5;
    SOLID_INFO("Hello! Var={0}", a);

    auto *app = SolidEngine::CreateApplication();
    app->Run();
    delete app;

    return 0;
}