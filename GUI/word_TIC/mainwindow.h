#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>
#include <vector>
#include <fstream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *selectedButton = nullptr;
    vector <QString> Words;
    int player = 1;
    int player1Wins = 0;
    int player2Wins = 0;
    int tieTimes = 0;
    int player1_single_Wins = 0;
    int computer_Wins = 0;
    int tie_single_Times = 0;
    bool isMultiPlayer = 1;


private slots:
    void onButtonClicked();
    void keyPressEvent(QKeyEvent *choice);
    void Default_dic();
    void Check_dic_status(ifstream& file);
    bool Search_Word(QString first_letter , QString second_letter , QString third_letter);
    bool is_win();
    bool isDraw();
    void resetGame();
    void RandomPlayer();
    void setSinglePlayerMode();
    void setMultiPlayerMode();
    void resetScores();
};
#endif // MAINWINDOW_H
