#ifndef Tic_Tac_Toe_HPP
#define Tic_Tac_Toe_HPP
#include <vector>
#include <string>
#include <iostream>

class TicTacToe
{
public:
    TicTacToe();
    ~TicTacToe();
    void run();
    void move(const int& x, const int& y);
    void showBoard();
private:
    enum gamestate { cont, over, tie };
    std::string gameMode;
    bool p2Turn = false;
    bool gameOver = false;
    int winner = 0;
    const int p1 = 1;
    const int p2 = 2;
    int posX = -1 , posY = -1;
    std::vector<std::vector<int>> board;
    void bestMove(int ai);
    int miniMax(std::vector<std::vector<int>>newBoard, int depth, int alpha, int beta, bool maxplayer, int& human, int& ai);
    int isOver(const std::vector<std::vector<int>>& finalBoard);
};


#endif