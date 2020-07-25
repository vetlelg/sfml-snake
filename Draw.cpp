#include "Engine.h"

void Engine::draw() {

    // Clear everything in the window
    m_window.clear(sf::Color::Black);

    // Return RectangleShape and draw it to the screen
    m_snake.draw(&m_window);
    m_food.draw(&m_window);


    // Display everything to the window
    m_window.display();

}
