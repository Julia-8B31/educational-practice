#include "obstacle.h"

Obstacle::Obstacle() : passed(false) {
    shape.setSize(sf::Vector2f(90, 90));  // Размер препятствия
    texture.loadFromFile("D:/Programming/project5/foto/preg2.png");
    shape.setTexture(&texture);
}

void Obstacle::update() {
    shape.move(-5.0f, 0);  // Движение препятствия влево
}

void Obstacle::setPosition(float x, float y) {
    shape.setPosition(x, y);
}