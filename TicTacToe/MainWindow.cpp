#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), ai(O) {
    ui->setupUi(this);

    currentPlayer = X;

    buttons = {
        { ui->btn_0_0, ui->btn_0_1, ui->btn_0_2 },
        { ui->btn_1_0, ui->btn_1_1, ui->btn_1_2 },
        { ui->btn_2_0, ui->btn_2_1, ui->btn_2_2 }
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            connect(buttons[i][j], &QPushButton::clicked, this, [=]() {
                handleButtonClick(i, j);  
                });
        }
    }

    connect(ui->btn_reset, &QPushButton::clicked, this, &MainWindow::resetGame);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handleButtonClick(int row, int col) {
    if (game.getBoard()[row][col] != NONE) {
        return; 
    }

    if (game.makeMove(row, col, currentPlayer)) {
        updateBoard();

        if (game.isGameOver()) {
            Player winner = game.checkWinner();
            if (winner == X) {
                ui->lbl_status->setText("Jucătorul X a câștigat!");
            }
            else if (winner == O) {
                ui->lbl_status->setText("AI-ul a câștigat!");
            }
            else {
                ui->lbl_status->setText("Remiză!");
            }
            return;
        }

        currentPlayer = O;
        makeAIMove();
    }
}

void MainWindow::makeAIMove() {
    if (currentPlayer == O) {
        std::pair<int, int> bestMove = ai.findBestMove(game);
        if (bestMove.first != -1) {
            game.makeMove(bestMove.first, bestMove.second, O);
            updateBoard();
        }

        if (game.isGameOver()) {
            Player winner = game.checkWinner();
            if (winner == O) {
                ui->lbl_status->setText("AI-ul a castigat !");
            }
            else {
                ui->lbl_status->setText("Remiza !");
            }
            return;
        }

        currentPlayer = X;
    }
}

void MainWindow::resetGame() {
    game.resetGame();
    currentPlayer = X;
    ui->lbl_status->setText("Jucatorul X incepe");
    updateBoard();
}

void MainWindow::updateBoard() {
    auto board = game.getBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == X) {
                buttons[i][j]->setText("X");
            }
            else if (board[i][j] == O) {
                buttons[i][j]->setText("O");
            }
            else {
                buttons[i][j]->setText("");  
            }
        }
    }
}
