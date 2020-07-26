#include "Engine.h"

void Engine::update() {
        m_snake.update(m_food.getGlobalBounds());
        m_food.update(m_snake.getHeadRectangle(), getRandomPosition());
}
