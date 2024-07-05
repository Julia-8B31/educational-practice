#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1280, 720), L"Endless runner");
    

    Texture textureSpace;
    textureSpace.loadFromFile("D:/Programming/project5/foto/sky.png");
    RectangleShape gamingBckground(Vector2f(1280,720));
    gamingBckground.setTexture(&textureSpace);

    RectangleShape gamingBckground2(Vector2f(1280,720));
    gamingBckground2.setTexture(&textureSpace);
    gamingBckground2.setPosition(Vector2f(1280,720));
    
    Vector2f pos;
    Clock clock;
    float time;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        
        window.display();
    }

    return 0;
}