#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Picture!");

	Texture Picture;
	Picture.loadFromFile("C:/Users/ula-a/OneDrive/Документы/Летняя практика 2024/foto/небо фон.png");
	Sprite Sprite1(Picture);

	Sprite1.setPosition(100, 50);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
					window.close();
		}

		window.clear(Color::White);
		window.draw(Sprite1);
		window.display();
	}

	return 0;
}
