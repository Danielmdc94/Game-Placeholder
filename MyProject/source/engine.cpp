#include "../include/engine.h"

Engine::Engine()
{
	window.create(VideoMode(WIN_W, WIN_H), NAME, sf::Style::Default, settings);
	window.setFramerateLimit(FPS);
}

void Engine::Start()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		double deltaTimeInSeconds = deltaTime.asSeconds();
		while (window.pollEvent(event))
			Input(event);
		Update(deltaTimeInSeconds);
		Render();
	}
}

void Engine::Input(Event event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        window.close();
        break;
    case sf::Event::KeyPressed:
        if (event.key.code == Keyboard::Escape)
            window.close();
        break;
    default:
        break;
    }
}

void Engine::Render()
{
	window.clear(Color::Black);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(sf::Color::Blue);
	shape.move(sf::Vector2f(200, 200));
	window.draw(shape);
	window.display();
}

void Engine::Update(double deltaTimeInSeconds)
{
	return ;
}