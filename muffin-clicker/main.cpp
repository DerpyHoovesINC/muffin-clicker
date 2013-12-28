#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 480), "Muffin clicker");

	sf::Texture muffin;
	if (!muffin.loadFromFile("../Debug/muffin.png"))
	{
		//Error handling
	}
	sf::Texture background;
	if (!background.loadFromFile("../Debug/background.png"))
	{
		//Error handling
	}
	background.setRepeated(true);

	sf::RectangleShape muffinSprite;
	muffinSprite.setPosition(sf::Vector2f(10, 10));
	muffinSprite.setTexture(&muffin);
	muffinSprite.setSize(sf::Vector2f(256, 256));

	sf::RectangleShape backgroundSprite(sf::Vector2f(800, 480));
	backgroundSprite.setTexture(&background);
	backgroundSprite.setPosition(sf::Vector2f(0, 0));
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 800, 480));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(backgroundSprite);

		window.draw(muffinSprite);

		window.display();
	}

	return 0;
}