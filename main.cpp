#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;


class Coin {
public:
    RectangleShape shape;
    Texture textureCoin;
    bool collected;

    Coin() {
        shape.setSize(Vector2f(120, 60));
        textureCoin.loadFromFile("D:/Programming/project5/foto/coinn.png");
        shape.setTexture(&textureCoin);
        collected = false;
    }

    void setPosition(float x, float y) {
        shape.setPosition(x, y);
    }
};

class CoinCollector {
private:
    int coinsCollected;

public:
    CoinCollector() {
        coinsCollected = 0;
    }

    void collectCoin() {
        coinsCollected++;
    }

    int getCoinsCollected() {
        return coinsCollected;
    }
};



int main()
{   
    RenderWindow window(VideoMode(1280, 720), L"Endless runner");
    
    int coinsCollected = 0; // добавление collected coins
     

    // Background
    Texture textureSpace;
    textureSpace.loadFromFile("D:/Programming/project5/foto/sky.png");
    RectangleShape gamingBckground(Vector2f(1280,720));
    gamingBckground.setTexture(&textureSpace);

    RectangleShape gamingBckground2(Vector2f(1280,720));
    gamingBckground2.setTexture(&textureSpace);
    gamingBckground2.setPosition(Vector2f(1280,0));

    // Road
    RectangleShape road(Vector2f(1280, 100));
    Texture textureRoad;
    textureRoad.loadFromFile("D:/Programming/project5/foto/road.png");
    road.setTexture(&textureRoad);
    road.setPosition(Vector2f(0, 620));

    // Player
    RectangleShape player(Vector2f(100, 100));
    Texture texturePlayer;
    texturePlayer.loadFromFile("D:/Programming/project5/foto/run2.png");
    player.setTexture(&texturePlayer);
    player.setPosition(Vector2f(50, 570));
    
    sf::Clock clock;

    bool isJumping = false;
    float jumpHeight = 0;

    Coin coin1, coin2, coin3;
    coin1.setPosition(800, 570);
    coin2.setPosition(1200, 570);
    coin3.setPosition(1600, 570);

    Coin coinsArr[] = {coin1, coin2, coin3};

    srand(time(0));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        float time = clock.getElapsedTime().asSeconds();
        
        
        if (Keyboard::isKeyPressed(Keyboard::Space) && !isJumping)
        {
            isJumping = true;
        } 

        if (time > 0.01)
        {
            clock.restart();
            
           //движение фона
            gamingBckground.move(Vector2f(-2.5, 0));
            
            if (gamingBckground.getPosition().x <= -1280)
            {
                gamingBckground.setPosition(1280, 0);
            }

            gamingBckground2.move(Vector2f(-2.5, 0));

            if (gamingBckground2.getPosition().x <= -1280)
            {
                gamingBckground2.setPosition(1280, 0);
            }
        }
        
        // прыжки
        if (isJumping)
        {
            if (jumpHeight < 100)
            {
                player.move(0, -5);
                jumpHeight += 5;
            }
            else
            {
                isJumping = false;
            }
        }
        else if (player.getPosition().y < 570)
        {
            player.move(0, 5);
        }

        // собирание монет
        for (int i = 0; i < 3; i++)
        {
            if (!coinsArr[i].collected)
            {
                coinsArr[i].shape.move(Vector2f(-2.5, 0));
            }

            if (player.getGlobalBounds().intersects(coinsArr[i].shape.getGlobalBounds()) && !coinsArr[i].collected)
            {
                coinsArr[i].collected = true;
                coinsCollected++; 
            }
        }
        
        window.clear();
       



        window.draw(gamingBckground);
        window.draw(gamingBckground2);
        window.draw(road);
        

        for (int i = 0; i < 3; i++)
        {
            if (!coinsArr[i].collected)
            {
                window.draw(coinsArr[i].shape);
            }
        }
        window.draw(player);


         // Отображение собранных монет
        Font font;
        font.loadFromFile("arial.ttf");
        Text text;
        text.setFont(font);
        text.setString("Coins: " + std::to_string(coinsCollected));
        text.setCharacterSize(24);
        text.setFillColor(Color::White);
        text.setPosition(10, 10);


        window.draw(text);
        window.display();
    }

    return 0;
}


