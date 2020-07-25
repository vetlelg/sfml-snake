#pragma once
#include <SFML\Graphics.hpp>
class Food
{

private:
    sf::RectangleShape m_body;
    sf::Vector2f m_position{ 100.0f, 100.0f };
    sf::Vector2f m_blockSize{ 10.0f, 10.0f };

public:
    Food();
    ~Food();

    void update();

    void draw(sf::RenderWindow* m_window);

    sf::FloatRect getGlobalBounds();
};

