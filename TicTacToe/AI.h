#ifndef AI_H
#define AI_H

#include "GameLogic.h"

class AI {
public:
    AI(Player aiPlayer);
    std::pair<int, int> findBestMove(GameLogic& game);
private:
    int minimax(GameLogic& game, bool isMaximizing);
    Player aiPlayer;
};

#endif
