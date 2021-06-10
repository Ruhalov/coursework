#include "../Game.h"
#include "../Menu.h"

int main()
{
    //init game
    Game game;


    while (game.running())
    {
       
        //update
        game.update();
        
        //render
        game.render();
    }
	return 0;
}