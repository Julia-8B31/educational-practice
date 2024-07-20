#ifndef COINS
#define COINS

#include <SFML/Graphics.hpp>

class Coin {
public:
    sf::RectangleShape shape;
    sf::Texture texture;
    bool collected;

    Coin();
    void setPosition(float x, float y);
};

class CoinCollector {
private:
    int coinsCollected;

public:
    CoinCollector();
    void collectCoin();
    void reset();
    int getCoinsCollected();
};

#endif