#pragma once

//extern SolidEngine::Application* SolidEngine::CreateApplication();
int main(int argc, char **argv)
{
    auto *app = SolidEngine::CreateApplication();
    app->Run();
    delete app;

    return 0;
}