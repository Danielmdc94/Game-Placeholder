#include "../include/engine.h"

Engine::Engine()
{
	window.create(VideoMode(WIN_W, WIN_H), NAME, sf::Style::Default, settings);
	window.setFramerateLimit(FPS);
}

Engine::~Engine()
{

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

void Engine::Load()
{

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

	window.draw(*player.GetSprite());

	window.draw(*enemy.GetSprite());

	window.display();
}

void Engine::Update(double deltaTimeInSeconds)
{
	player.Update(deltaTimeInSeconds);
	enemy.Update(deltaTimeInSeconds);

	return ;
}