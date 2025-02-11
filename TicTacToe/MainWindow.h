#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include "GameLogic.h"
#include "AI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick(int row, int col);
    void makeAIMove();
    void resetGame();
    void updateBoard();

private:
    Ui::MainWindowClass* ui;
    GameLogic game;  
    AI ai;
    QVector<QVector<QPushButton*>> buttons; 
    Player currentPlayer; 

};

#endif // MAINWINDOW_H
