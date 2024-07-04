#include "../include/engine.h"

Engine::Engine()
{
	window.create(VideoMode(WIN_W, WIN_H), NAME);
	window.setFramerateLimit(60);
}

void Engine::start()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		double deltaTimeAsSeconds = deltaTime.asSeconds();
		while (window.pollEvent(event))
			input(event);
		update(deltaTimeAsSeconds);
		render();
	}
}

void Engine::input(Event event)
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

void Engine::render()
{
	window.clear(Color::Black);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
	window.display();
}

void Engine::update(double deltaTimeInSeconds)
{
	return ;
}