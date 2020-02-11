#include <Engine.h>

class GameApp : public Engine::Application {
public:
	GameApp() {
	}

	~GameApp() {

	}
};

Engine::Application* Engine::createApplication() {
	return new GameApp();
}