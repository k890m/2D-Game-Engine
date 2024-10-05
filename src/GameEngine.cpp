#include "GameEngine.h"

GameEngine::GameEngine() :
	window(sf::VideoMode(800, 800), "Game Engine")
	physicsWorld(b2Vec2(0.0f, -9.8f))
{
	window.setFramerateLimit(60);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(400.0f / 30.0f, 100.0f / 30.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	dynamicBody->CreateFixture(&fixtureDef);

	boxShape.setSize(sf::Vector2f(100.0f, 100.0f));
	boxShape.setFillColor(sf::Color::Blue);
	boxShape.setOrigin(boxShape.getSize().x / 2, boxShape.getSize().y / 2);

	// Ground Body
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(400.0f / 30.0f, 600.0f / 30.0f);  
	groundBody = physicsWorld.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(400.0f / 30.0f, 10.0f / 30.0f);  
	groundBody->CreateFixture(&groundBox, 0.0f);
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

	b2Vec2 position = dynamicBody->GetPosition();
	float angle = dynamicBody->GetAngle();

	boxShape.setPosition(position.x * 30.0f, position.y * 30.0f);
	boxShape.setRotation(angle * 180.0f / b2_pi);

}

void GameEngine::render() {
	window.clear(sf::Color::Black);
	window.draw(boxShape);
	window.draw(groundShape);
	window.display();
}

void GameEngine::processInput() {
	sf::Event even;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
	// Left key
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		dynamicBody->ApplyForceToCenter(b2Vec2(-10.0f, 0.0f), true);
	}
	
	//Right Key
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		dynamicBody->ApplyForceToCenter(b2Vec2(10.0f, 0.0f), true);
	}

}