#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::vector<int>> board(
        3, std::vector<int>(3, 0)
    );
    bool p2Turn = false;
    bool gameOver = false;
    int winner = 1;
    int x;
    int y;
    const int p1 = 1;
    const int p2 = 2;


    while(!gameOver){
        std::cout << "What row would you like?" << std::endl;
        std::cin >> x;
        x -= 1;
        std::cout << "What column would you like?" << std::endl;
        std::cin >> y;
        y -= 1;
        if(y == -1 || x == -1){
            gameOver = true;
            break;
        }
        if(board[x][y] == 0){
            if(!p2Turn)
                board[x][y] = p1;
            else
                board[x][y] = p2;
            p2Turn = !p2Turn;
            for(auto row: board){
                std::cout << "   ";
                for(int i: row){
                    std::cout << i << " | ";
                }
                std::cout << "\n ---------------" << std::endl;
            }
        }
        else
            std::cout << "Please enter a valid row and column." << std::endl;
        std::cout << "value at board[x][y] is " << board[x][y] << std::endl;

        //check func
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
        
    }
    std::cout << "Congratulations player " << winner << std::endl;
    /*
    
    std::cout << "Hello World!" << std::endl;
    std::vector<std::string> msg = {"Hello", "World", "this", "is", "a", "test"};
    msg.resize(10);
    for(std::vector<std::string>::iterator word = msg.begin(); word < msg.end(); word++){
        std::cout << *word + " " ;
    }
    std::cout << "!" << std::endl;
    std::cout << msg.capacity() << "\n";
    const int j = 1;
    int i = 1;
    std::cout << i + 2147483647;
    */
    return 0;


    
}