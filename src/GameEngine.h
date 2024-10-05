#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class GameEngine {

public:
    GameEngine();
    void run();

private:
    void processInput();
    void update();
    void render();

    sf::RenderWindow window;
    b2World physicsWorld;

    b2Body* dynamicBody;
    sf::RectangleShape boxShape;

    b2Body* groundBody;

};

#endif
