#include "../Game.h"
#include "../Menu.h"

int main()
{
    //init game
    Game game;


    while (game.running())
    {
       
        //update
        game.updateDeltaTime();
        game.update();
        
        //render
        game.render();
    }
	return 0;
}