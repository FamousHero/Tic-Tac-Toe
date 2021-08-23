#include "ticTacToe.hpp"

ticTacToe::ticTacToe()
    :board{3,std::vector<int>(3,0)}
{
}

ticTacToe::~ticTacToe()
{
}

void ticTacToe::run(){
    while(!gameOver){
        std::cout << "What row would you like?" << std::endl;
        std::cin >> posX;
        std::cout << "What column would you like?" << std::endl;
        std::cin >> posY;
        if(posX < 0 || posX > 3 || posY < 0 || posY > 3){
            std::cout << "Please enter a valid row and column." << std::endl;
        }
        else{
            move(posX-1, posY-1);
            showBoard();
        }
    }
}
void ticTacToe::move(const int& x, const int& y){
    if(y == -1 && x == -1){
        std::cout << "Game terminated. Final Board: " << std::endl;
        gameOver = true;
        return;
    }
    if(board[x][y] == 0){
        if(!p2Turn)
            board[x][y] = p1;
        else
            board[x][y] = p2;
        p2Turn = !p2Turn;
    }
}

void ticTacToe::showBoard(){
    if(isOver() && posX != 0 && posY != 0)
        std::cout << "Congratulations player " << winner << "! You are the winner!" << std::endl;
    for(auto row: board){
        std::cout << "   ";
        for(int i: row){
            std::cout << i << " | ";
        }
        std::cout << "\n ---------------" << std::endl;
    }
}

bool ticTacToe::isOver(){
    for(int row = 0; row < board.size(); row++){
        if(board[row][0] != 0 && board[row][0] == board[row][1] && board[row][1] == board[row][2]){
            gameOver = true;
            winner += !p2Turn;
        }
        else if(board[0][row] != 0 && board[0][row] == board[1][row] && board[1][row] == board[2][row]){
            gameOver = true;
            winner += !p2Turn;
        }

    }
    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        gameOver = true;
        winner += !p2Turn;
    }
    else if(board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        gameOver = true;
        winner += !p2Turn;
    }
    return gameOver;
}