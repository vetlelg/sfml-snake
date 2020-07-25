#include "Engine.h"


Engine::Engine() {
    m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), "Snake");
}

Engine::~Engine() {
}

const int Engine::getWindowWidth() {
    return m_windowWidth;
}

const int Engine::getWindowHeight() {
    return m_windowHeight;
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
