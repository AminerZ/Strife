#pragma once
#include "Core.h"

namespace Engine {
	class HOS_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in client
	Application* createApplication();
}

