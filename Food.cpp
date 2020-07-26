#include "Food.h"
#include "Engine.h"

Food::Food() {
    m_body.setSize(m_blockSize);
    m_body.setFillColor(sf::Color::Red);
    m_body.setPosition(m_position);
}


Food::~Food()
{
}

void Food::update(sf::FloatRect headRectangle, sf::Vector2f position) {
    collision(headRectangle, position);
}

sf::FloatRect Food::getGlobalBounds() {
    return m_body.getGlobalBounds();
}

void Food::draw(sf::RenderWindow* m_window) {
    m_window->draw(m_body);
}

void Food::collision(sf::FloatRect headRectangle, sf::Vector2f position) {
    if (m_body.getGlobalBounds().intersects(headRectangle)) {
        m_body.setPosition(position);
    }
}
