#include "GameEngine.h"

GameEngine::GameEngine() :
	window(sf::VideoMode(800, 800), "Game Engine")
	physicsWorld(b2Vec2(0.0f, -9.8f))
{
	window.setFramerateLimit(60);
}

void GameEngine::run() {
	while (window.isOpen()) {
		processInput();
		update();
		render();
	}
}

void GameEngine::update() {
	physicsWorld.Step(1.0f / 60.0f, 6, 2);
}

void GameEngine::render() {
	window.clear(sf::Color::Black);
	window.display();
}

void GameEngine::processInput() {
	sf::Event even;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}