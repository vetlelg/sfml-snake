#pragma once
#include <SFML\Graphics.hpp>
#include "Snake.h"
#include "Food.h"

class Engine
{
private:
    sf::RenderWindow m_window;
    sf::Clock m_clock; // Start the clock, for handling the time
    sf::Time m_moveTime{ sf::seconds(0.07f) };

    Snake m_snake;
    Food m_food;


    const int m_windowWidth{ 800 };
    const int m_windowHeight{ 600 };

    void input();
    void update();
    void draw();

public:
    Engine();
    ~Engine();

    const int getWindowWidth();
    const int getWindowHeight();

    int getRandomInt(int min, int max);
    sf::Vector2f getRandomPosition();

    void start();
};

