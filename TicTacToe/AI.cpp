#include "AI.h"

AI::AI(Player aiPlayer) {
    this->aiPlayer = aiPlayer;
}

std::pair<int, int> AI::findBestMove(GameLogic& game) {
    int bestScore = -1000;
    std::pair<int, int> bestMove = { -1, -1 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game.getBoard()[i][j] == NONE) {
                game.makeMove(i, j, aiPlayer);
                int score = minimax(game, false);
                game.makeMove(i, j, NONE);

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = { i, j };
                }
            }
        }
    }
    return bestMove;
}

int AI::minimax(GameLogic& game, bool isMaximizing) {
    Player winner = game.checkWinner();
    if (winner == aiPlayer) return 10;
    if (winner != NONE) return -10;

    int bestScore = isMaximizing ? -1000 : 1000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game.getBoard()[i][j] == NONE) {
                game.makeMove(i, j, isMaximizing ? aiPlayer : (aiPlayer == X ? O : X));
                int score = minimax(game, !isMaximizing);
                game.makeMove(i, j, NONE);
                bestScore = isMaximizing ? std::max(bestScore, score) : std::min(bestScore, score);
            }
        }
    }
    return bestScore;
}
