#include "Engine.h"

// Handle all the input in the game
void Engine::input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_snake.moveLeft();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_snake.moveRight();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        m_snake.moveUp();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        m_snake.moveDown();
}
