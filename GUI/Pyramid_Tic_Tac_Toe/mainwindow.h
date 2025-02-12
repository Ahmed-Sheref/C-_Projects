#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;  // This connects to the UI file
    bool isXTurn;  // Track whose turn it is (X or O)
    bool isMultiPlayer;
    int player1Wins = 0;
    int player2Wins = 0;
    int tieTimes = 0;
    int player1_single_Wins = 0;
    int computer_Wins = 0;
    int tie_single_Times = 0;


private slots:
    void onButtonClicked();  // Slot to handle button click
    bool checkWin();
    void resetGame();
    bool isDraw();
    void RandomPlayer();
    void setSinglePlayerMode();
    void setMultiPlayerMode();
    void resetScores();
    void ResetScoreButtonClicked();

};
#endif // MAINWINDOW_H
