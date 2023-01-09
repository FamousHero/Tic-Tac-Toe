#include "ticTacToe.hpp"

TicTacToe::TicTacToe()
    :board{3,std::vector<int>(3,0)}
{
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::run(){
    std::cout << "Would you like (2 Player) or (AI)?" << std::endl;
    while(gameMode != "2 Player" && gameMode != "AI"){
        std::getline(std::cin, gameMode);
        if(gameMode != "2 Player" && gameMode != "AI"){
            std::cout << "Please enter a valid game mode: (2 Player) or (AI)?" << std::endl;
        }
    }
    if(gameMode == "AI"){
        std::string player;
        while(player != "Player 1" && player != "Player 2"){
            std::cout << "Would you like to be (Player 1) or (Player 2)?" << std::endl;
            std::getline(std::cin, player);
        }
        if(player == "Player 2"){
            bestMove(p1);
            showBoard();
        }
    }
    while(!gameOver){
        std::cout << "What row would you like?" << std::endl;
        std::cin >> posX;
        std::cout << "What column would you like?" << std::endl;
        std::cin >> posY;
        if(posX < 0 || posX > 3 || posY < 0 || posY > 3 || (posX != 0 && posY != 0 && board[posX-1][posY-1] != 0)){
            std::cout << "Please enter a valid row and column." << std::endl;
        }
        else{
            move(posX-1, posY-1);
            showBoard();
            if(gameMode == "AI" && !gameOver){
                std::cout << "Player " << p2Turn + 1 << " turn: \n" << std::endl;
                bestMove(p2Turn + 1);
                showBoard();
            }
        }
    }
}
void TicTacToe::move(const int& x, const int& y){
    if(y == -1 && x == -1){
        std::cout << "Game terminated. Final Board: " << std::endl;
        gameOver = true;
        return;
    }
    if (board[x][y] == 0) {
        if (!p2Turn)
            board[x][y] = p1;
        else
            board[x][y] = p2;
        p2Turn = !p2Turn;
    }
}

void TicTacToe::showBoard(){
    int currstate = isOver(board);
    if (currstate == over) {
        gameOver = true;
        winner = !p2Turn+1;
        std::cout << "Congratulations player " << winner << "! You are the winner!" << std::endl;
    }
    else if (currstate == tie) {
        gameOver = true;
        std::cout << "Tie!" << std::endl;
    }
    for(auto row: board){
        std::cout << "   ";
        for(int i: row){
            std::cout << i << " | ";
        }
        std::cout << "\n ---------------" << std::endl;
    }
}

int TicTacToe::isOver(const std::vector<std::vector<int>>& finalBoard){
    for(int row = 0; row < finalBoard.size(); row++){
        if(finalBoard[row][0] != 0 && finalBoard[row][0] == finalBoard[row][1] && finalBoard[row][1] == finalBoard[row][2]){
            return over;
        }
        else if(finalBoard[0][row] != 0 && finalBoard[0][row] == finalBoard[1][row] && finalBoard[1][row] == finalBoard[2][row]){
            return over;
        }

    }
    if(finalBoard[0][0] != 0 && finalBoard[0][0] == finalBoard[1][1] && finalBoard[1][1] == finalBoard[2][2]){
        return over;
    }
    else if(finalBoard[0][2] != 0 && finalBoard[0][2] == finalBoard[1][1] && finalBoard[1][1] == finalBoard[2][0]){
        return over;
    }

    for (auto& row : finalBoard) {
        for (int j : row) {
            if (j == 0)
                return cont;
        }
    }
    return tie;
}
void TicTacToe::bestMove(int ai) {
    int human = ai == p1 ? p2 : p1;
    std::pair<int,int> bestCoord;
    int bestScore = INT32_MIN;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 0) {
                board[i][j] = ai;
                int score = miniMax(board, 0, INT32_MIN, INT32_MAX, false, human, ai);
                board[i][j] = 0;
                if (score > bestScore) {
                    bestScore = score;
                    bestCoord = { i,j };
                }

            }
        }
    }
    board[bestCoord.first][bestCoord.second] = ai;
    p2Turn = !p2Turn;
    
}

int TicTacToe::miniMax(std::vector<std::vector<int>> boardcpy, int depth, int alpha, int beta, bool maxplayer, int& human, int& ai) {
    int currstate = isOver(boardcpy);
    if (currstate == tie)
        return 0;
    else if(currstate == over)
        if (maxplayer)
            return -10+depth;
        else
            return 10 - depth;
    
    if (maxplayer) {
        int bestScore = INT32_MIN;
        for (int i = 0; i < board.size(); ++i) {    
            for (int j = 0; j < board[i].size(); ++j) {
                if (boardcpy[i][j] == 0) {
                    boardcpy[i][j] = ai;
                    int score = miniMax(boardcpy, depth + 1, alpha, beta, !maxplayer, human, ai);
                    boardcpy[i][j] = 0;
                    bestScore = std::max(bestScore, score);
                    alpha = std::max(alpha, score);
                    if (beta < alpha)
                        break;
                }
            }
        }
        return bestScore;
    }
    if (!maxplayer) {
        int bestScore = INT32_MAX;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (boardcpy[i][j] == 0) {
                    boardcpy[i][j] = human;
                    int score = miniMax(boardcpy, depth + 1, alpha, beta, !maxplayer, human, ai);
                    boardcpy[i][j] = 0;
                    bestScore = std::min(bestScore, score);
                    beta = std::min(beta, score);
                    if (beta <  alpha)
                        break;
                }
            }
        }
        return bestScore;
    }
}