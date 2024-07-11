#include "../include/game.h"

int main(int argc, void** argv[])
{
	Game game;
	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	return EXIT_SUCCESS;
}