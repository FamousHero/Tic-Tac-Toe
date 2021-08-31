#include "TicTacToe.hpp"
#include <iostream>
#include <string>
int main(){
    bool is_running = true;
    std::string newGame;
    while(is_running){
        newGame = "";
        TicTacToe* game =  new TicTacToe();
        game->run();
        delete game;
        while(newGame != "Yes" && newGame != "No")
        {
            std::cout << "New Game? (Yes/No)" <<std::endl;
            std::cin >> newGame;
        }
        if(newGame == "No")
            is_running = false;
    }
    std::cout << "Goodbye...\n\n\n";
    system("pause");
    return 0;

  
    
}
