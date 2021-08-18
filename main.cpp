#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::vector<int>> board(
        3, std::vector<int>(3, 0)
    );
    bool p1Turn = true;
    bool gameOver = false;
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
            if(p1Turn)
                board[x][y] = p1;
            else
                board[x][y] = p2;
            p1Turn = !p1Turn;
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
    }

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