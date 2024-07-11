#include "../include/engine.h"
#include "../include/game.h"

int main()
{
	Engine engine;

	engine.Start();

	return EXIT_SUCCESS;
}

int main2(int argc, void** argv[])
{
	Game game;
	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	return 0;
}