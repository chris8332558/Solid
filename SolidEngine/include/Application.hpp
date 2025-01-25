#pragma once

namespace SolidEngine {
	class Application 
	{
	public:
		Application(); 
		virtual ~Application();

		virtual void Run();
	};

	// To be defined in Client (SandboxApp)
	Application* CreateApplication();
}

