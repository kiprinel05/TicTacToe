#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>

enum Player { NONE = 0, X, O };

class GameLogic {
public:
    GameLogic();
    bool makeMove(int row, int col, Player player);
    bool isGameOver();
    Player checkWinner();
    void resetGame();
    std::vector<std::vector<Player>> getBoard();
private:
    std::vector<std::vector<Player>> board;
};

#endif
