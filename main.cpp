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
        textureCoin.loadFromFile("D:/Programming/project5/foto/coin.png");
        shape.setTexture(&textureCoin);
        collected = false;
    }

    void setPosition(float x, float y) {
        shape.setPosition(x, y);
    }
};



int main()
{   

    
    RenderWindow window(sf::VideoMode(1280, 720), L"Endless runner");
    
    //ФОН
    Texture textureSpace;
    textureSpace.loadFromFile("D:/Programming/project5/foto/sky.png");
    RectangleShape gamingBckground(Vector2f(1280,720));
    gamingBckground.setTexture(&textureSpace);

    RectangleShape gamingBckground2(Vector2f(1280,720));
    gamingBckground2.setTexture(&textureSpace);
    gamingBckground2.setPosition(Vector2f(1280,0));


    // ДОРОГА
    RectangleShape road(Vector2f(1280, 100));
    Texture textureRoad;
    textureRoad.loadFromFile("D:/Programming/project5/foto/road.png");
    road.setTexture(&textureRoad);
    road.setPosition(Vector2f(0, 620));

        // ПЕРСОНАЖ
    RectangleShape player(Vector2f(100, 100));
    Texture texturePlayer;
    texturePlayer.loadFromFile("D:/Programming/project5/foto/running.png");
    player.setTexture(&texturePlayer);
    player.setPosition(Vector2f(50, 570));
    
    Clock clock;


    bool isJumping = false;
    float jumpHeight = 0;

    float playerSpeed = 2.5f;

    //Vector2f pos;
    //Clock clock;
    //float time;

    

    Coin coin1, coin2, coin3;
    coin1.setPosition(800, 570);
    coin2.setPosition(1200, 570);
    coin3.setPosition(1600, 570);

    Coin coinsArr[] = {coin1, coin2, coin3};

    srand(time(0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        float time = clock.getElapsedTime().asSeconds();
        
        // Handle player input
        if (Keyboard::isKeyPressed(Keyboard::Space) && !isJumping)
        {
            isJumping = true;
        } 


         //time = clock.getElapsedTime().asSeconds();



        if (time > 0.01)
        {
            clock.restart();
            
            // Движение фона
            gamingBckground.move(Vector2f(-2.5, 0));
            
            if (gamingBckground.getPosition().x <= -1280)
            {
                gamingBckground.setPosition(1280, 0);
            }

            gamingBckground2.move(Vector2f(-2.5, 0));

            if (gamingBckground2.getPosition().x <= -1280)
            {
                gamingBckground2.setPosition(1280, 0);
            }// Make the player jump
            if (isJumping)
            {
                player.move(Vector2f(0, -5));
                jumpHeight += 5;
                if (jumpHeight >= 100)
                {
                    isJumping = false;
                    //jumpHeight = 0;
                    
                }
            }
            else
            {
                player.move(Vector2f(0, 5));
                if (player.getPosition().y >= 570) {
                    player.setPosition(player.getPosition().x, 570);
                }
                player.move(Vector2f(playerSpeed, 0));
                if (player.getPosition().x >= 1230) {
                    player.setPosition(50, 570);
                }
            }
            for (int i = 0; i < 3; i++) {
                if (!coinsArr[i].collected && player.getGlobalBounds().intersects(coinsArr[i].shape.getGlobalBounds())) {
                    coinsArr[i].collected = true;
                    // Add any score or effect for collecting the coin here
                }
                coinsArr[i].shape.move(Vector2f(-2.5, 0));
                if (coinsArr[i].shape.getPosition().x <= -30) {
                    coinsArr[i].setPosition(rand() % 800 + 1280, 570);
                    coinsArr[i].collected = false;
                }
            }
        }
        

        window.clear();
        window.draw(gamingBckground);
        window.draw(gamingBckground2);
        window.draw(road);
        
        for (int i = 0; i < 3; i++) {
            if (!coinsArr[i].collected) {
                window.draw(coinsArr[i].shape);
            }
        }
        window.draw(player);
        window.display();
    }
    
    return 0;
}

