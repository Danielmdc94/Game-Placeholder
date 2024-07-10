#include "../include/game.h"
#include "../include/window.h"

int main2(int argc, void** argv[])
{
	Game game;
	while (!game.GetWindow()->IsDone())
	{
		//game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	return 0;
}