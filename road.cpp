#include "road.h"

Road::Road() {
    shape.setSize(sf::Vector2f(1280, 100));
    texture.loadFromFile("D:/Programming/project5/foto/road.png");
    shape.setTexture(&texture);
    shape.setPosition(sf::Vector2f(0, 620));
}