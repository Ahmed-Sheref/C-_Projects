#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    bool is_Player_1 = 1;
    bool is_MultiPlayer = 1;

private slots:
    void digit_pressed();
    void setSinglePlayerMode();
    void setMultiPlayerMode();
    void Update_Board (int column);
    void makeRandomMove();
    bool is_win();
    void resetBoard();
    bool is_draw();
    void resett();
    // void showWinnerMessage();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
