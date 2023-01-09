#include "ticTacToe.hpp"
#include <iostream>
#include <string>
int main(){
    bool is_running = true;
    std::string newGame;
    while(is_running){
        newGame = "";
        TicTacToe* game =  new TicTacToe();
        game->run();
        while(newGame != "Yes" && newGame != "No")
        {
            std::cout << "New Game? (Yes/No)" <<std::endl;
            std::cin >> newGame;
        }
        std::cin.ignore(256, '\n'); //clear \n before next std::cin if rematch
        if(newGame == "No")         //should be max limit if worried about overflow
            is_running = false;
        delete game;
    }
    std::cout << "Goodbye...Press any key to close.";
    std::cin.get();
    return 0;

  
    
}
