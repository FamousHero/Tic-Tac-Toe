#include "TicTacToe.hpp"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
int main(){

    TicTacToe* game =  new TicTacToe();
    game->run();
    delete game;
    return 0;

  
    
}
