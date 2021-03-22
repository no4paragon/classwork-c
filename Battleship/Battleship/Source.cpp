#include "Board.h"
#include <iostream>
using namespace std;

int main()
{   

    Board player;

    player.tutorial();

    player.setShipsOpp();
    player.setShips();
    
    player.attachShips();
    player.attachShipsOpp();
    
    
    return 0;
}