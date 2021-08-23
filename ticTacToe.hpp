#ifndef Tic_Tac_Toe_HPP
#define Tic_Tac_Toe_HPP
#include <vector>
#include <string>
#include <iostream>

class ticTacToe
{
public:
    ticTacToe();
    ~ticTacToe();
    void run();
    void move(const int& x, const int& y);
    void showBoard();
private:
    bool p2Turn = false;
    bool gameOver = false;
    int winner = 0;
    const int p1 = 1;
    const int p2 = 2;
    int posX, posY;
    std::vector<std::vector<int>> board;

    bool isOver();
};


#endif