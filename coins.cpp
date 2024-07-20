#include "coins.h"

Coin::Coin() {
    shape.setSize(sf::Vector2f(120, 60));
    texture.loadFromFile("foto/coinn.png");
    shape.setTexture(&texture);
    collected = false;
}

void Coin::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

CoinCollector::CoinCollector() {
    coinsCollected = 0;
}

void CoinCollector::collectCoin() {
    coinsCollected++;
}

int CoinCollector::getCoinsCollected() {
    return coinsCollected;
}

void CoinCollector::reset() {
    coinsCollected = 0;
}