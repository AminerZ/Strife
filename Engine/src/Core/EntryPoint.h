#pragma once

#ifdef HOS_PLATFORM_WINDOWS

extern Engine::Application* Engine::createApplication();

int main(int argc, char** argv) {
	auto app = Engine::createApplication();
	app->run();
	delete app;
}

#else
	#error Hands of Strife only supports Windows!
#endif