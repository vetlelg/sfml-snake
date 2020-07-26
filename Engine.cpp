#include "Engine.h"
#include <cstdlib>
#include <ctime>

Engine::Engine() {
    m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), "Snake");
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

Engine::~Engine() {
}

const int Engine::getWindowWidth() {
    return m_windowWidth;
}

const int Engine::getWindowHeight() {
    return m_windowHeight;
}

int Engine::getRandomInt(int min, int max) {
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

sf::Vector2f Engine::getRandomPosition() {
    float x { static_cast<float>(getRandomInt(0, m_windowWidth)) };
    float y { static_cast<float>(getRandomInt(0, m_windowHeight)) };
    sf::Vector2f position { x, y };
    return position;
}

void Engine::start() {

    // Start the game loop, and stop if the window is closed
    while (m_window.isOpen()) {

        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        // Check if it's time to move
        if (m_clock.getElapsedTime() >= m_moveTime) {
            m_clock.restart();
            input(); // Call the function for handling all the input in the game
            update(); // Update the values of everything in the game
        }
        draw(); // Draw everything to the window
    }

}
