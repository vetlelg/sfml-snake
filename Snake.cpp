#include "Snake.h"
#include "Engine.h"

#include <iostream>

Snake::Snake() {
    m_body.setSize(m_blockSize);
    m_body.setFillColor(sf::Color::White);
    m_body.setPosition(m_position);
    m_snakeBody = { m_body };
    m_previousPosition = { m_body };
}

Snake::~Snake()
{
}

void Snake::moveLeft() {
    if (m_direction != RIGHT && m_direction != LEFT) {
        m_changeDirection = true;
        m_direction = LEFT;
    }
}

void Snake::moveRight() {
    if (m_direction != LEFT && m_direction != RIGHT) {
        m_changeDirection = true;
        m_direction = RIGHT;
    }
}

void Snake::moveUp() {
    if (m_direction != DOWN && m_direction != UP) {
        m_changeDirection = true;
        m_direction = UP;
    }
}

void Snake::moveDown() {
    if (m_direction != UP && m_direction != DOWN) {
        m_changeDirection = true;
        m_direction = DOWN;
    }
}

void Snake::move() {

    // Save the previous position of the snake
    for (int i{ 0 }; i < m_snakeLength; i++) {
        m_previousPosition[i] = m_snakeBody[i];
    }

    // Update position of the snake's body to the new position
    if (m_snakeLength > 1) {
        for (int i{ 1 }; i < m_snakeLength; i++) {
            m_snakeBody[i] = m_previousPosition[i - 1];
        }
    }

    // Update position of the snake's head
    switch (m_direction) {
    case LEFT:
        m_position.x -= m_speed;
        break;
    case RIGHT:
        m_position.x += m_speed;
        break;
    case UP:
        m_position.y -= m_speed;
        break;
    case DOWN:
        m_position.y += m_speed;
        break;
    }

    m_snakeBody[0].setPosition(m_position);
}

/*
// NOT FINISHED
// Check if the snake hit something, and reset the position of the snake
void Snake::hitSomething() {
    if (getGlobalBounds().left < 0 || getGlobalBounds().top < 0 || getGlobalBounds().top + getGlobalBounds().height > 600
        || getGlobalBounds().left + getGlobalBounds().width > 800) {
        m_position.x = 400.0f;
        m_position.y = 300.0f;
    }
}
*/

void Snake::update(sf::FloatRect foodRectangle) {

    move();


    collision(foodRectangle);

    m_changeDirection = false;

}

sf::FloatRect Snake::getHeadRectangle() {
    sf::FloatRect headRectangle = m_snakeBody[0].getGlobalBounds();
    return headRectangle;
}

void Snake::draw(sf::RenderWindow* m_window) {
    for (int i{ 0 }; i < m_snakeLength; i++) {
        m_window->draw(m_snakeBody[i]);
    }
}


// NOT FINISHED
void Snake::collision(sf::FloatRect foodRectangle) {
    if (getHeadRectangle().intersects(foodRectangle)) {
        m_snakeBody.push_back(m_previousPosition[m_snakeLength - 1]);
        m_previousPosition.push_back(m_previousPosition[m_snakeLength - 1]);
        ++m_snakeLength;
    }
}
