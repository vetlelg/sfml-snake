#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Snake
{
private:
    // Enum for each direction
    enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    Direction m_direction{ LEFT };
    sf::RectangleShape m_body;
    sf::Vector2f m_position{ 400.0f, 300.0f };
    sf::Vector2f m_blockSize{ 10.0f, 10.0f };
    std::vector<sf::RectangleShape> m_snakeBody;
    std::vector<sf::RectangleShape> m_previousPosition;

    float m_speed{ 10.0f }; // Number of pixels the snake moves each time
    bool m_changeDirection{ false }; // Check if the direction changes, and move immediately
    int m_snakeLength{ 1 };

public:
    Snake();
    ~Snake();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void move();
    void hitSomething();
    void update(sf::FloatRect foodRectangle);
    sf::FloatRect getHeadRectangle();

    void draw(sf::RenderWindow* m_window);

    void collision(sf::FloatRect foodRectangle);

    
};

