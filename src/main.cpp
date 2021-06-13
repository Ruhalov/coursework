#include "../Game.h"

int main()
{
    //init game
    Game game;

    while (game.running())
    {
        game.update();
        game.render();
    }
	return 0;
}