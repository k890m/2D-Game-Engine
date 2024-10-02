#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

int main() {
    // Set up the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 800), "2D Game Engine");
    window.setFramerateLimit(60);

    // Set up the Box2D world with gravity
    b2Vec2 gravity(0.0f, -9.8f); // Gravity pointing down
    b2World world(gravity);

    // Basic game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Step Box2D simulation
        world.Step(1.0f / 60.0f, 6, 2);

        // Clear the window
        window.clear(sf::Color::Black);

        // Render game objects here

        // Display the back buffer
        window.display();
    }

    return 0;
}
