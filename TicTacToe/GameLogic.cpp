#include "GameLogic.h"

GameLogic::GameLogic() {
    board = std::vector<std::vector<Player>>(3, std::vector<Player>(3, NONE));
}

bool GameLogic::makeMove(int row, int col, Player player) {
    if (board[row][col] == NONE) {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool GameLogic::isGameOver() {
    return checkWinner() != NONE;
}

Player GameLogic::checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != NONE && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

        if (board[0][i] != NONE && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] != NONE && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != NONE && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return NONE;
}

void GameLogic::resetGame() {
    board = std::vector<std::vector<Player>>(3, std::vector<Player>(3, NONE));
}

std::vector<std::vector<Player>> GameLogic::getBoard() {
    return board;
}
