#ifndef MINIMAX_AI_HPP
#define MINIMAX_AI_HPP
#include <vector>

class MiniMaxAI{
    public:
        MiniMaxAI();
        ~MiniMaxAI();
        std::pair<int, int> bestMove(std::vector<std::vector<int>> newBoard, int depth, int alpha, int beta, bool maxplayer);
    private:
};

#endif