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

    void update(sf::FloatRect headRectangle, sf::Vector2f position);

    void draw(sf::RenderWindow* m_window);

    void collision(sf::FloatRect headRectangle, sf::Vector2f position);

    sf::FloatRect getGlobalBounds();
};

