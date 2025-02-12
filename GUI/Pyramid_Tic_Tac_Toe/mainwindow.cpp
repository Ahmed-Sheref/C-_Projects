#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set initial game mode to multiplayer (two players)
    isMultiPlayer = true;  // If true, it's two-player mode, else it's single-player mode

    isXTurn = true;  // Start with 'X'

    // Connect all the buttons to the same slot (onButtonClicked)
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    // Connect the player type selection buttons
    connect(ui->Button_player, &QPushButton::clicked, this, &MainWindow::setSinglePlayerMode);
    connect(ui->Button_multi, &QPushButton::clicked, this, &MainWindow::setMultiPlayerMode);

    // Connect the Reset_score button to the reset scores slot
    connect(ui->Reset_score, &QPushButton::clicked, this, &MainWindow::ResetScoreButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSinglePlayerMode()
{
    // Set game mode to single-player (one player vs AI)
    isMultiPlayer = false;
    ui->label_2->setText("Computer (O)");
    ui->Game_mode->setText("Single Player");

    // Update the UI with the current single-player scores
    ui->player_1_wins->setText(QString::number(player1_single_Wins));
    ui->player_2_wins->setText(QString::number(computer_Wins));
    ui->Tie_Times->setText(QString::number(tie_single_Times));

    resetGame();  // Reset game state when switching mode
}

void MainWindow::setMultiPlayerMode()
{
    // Set game mode to multiplayer (two human players)
    isMultiPlayer = true;
    ui->label_2->setText("Player 2 (O)");
    ui->Game_mode->setText("Multiplayer");

    // Update the UI with the current multiplayer scores
    ui->player_1_wins->setText(QString::number(player1Wins));
    ui->player_2_wins->setText(QString::number(player2Wins));
    ui->Tie_Times->setText(QString::number(tieTimes));

    resetGame();  // Reset game state when switching mode
}

void MainWindow::onButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    if (clickedButton == nullptr) return;

    // If the button already has text (X or O), ignore the click
    if (!clickedButton->text().isEmpty()) return;

    // Set the button's text to X or O based on whose turn it is
    if (isXTurn) {
        clickedButton->setText("X");
        isXTurn = false;
    } else {
        clickedButton->setText("O");
        isXTurn = true;
    }

    // Disable the button after it's clicked
    clickedButton->setEnabled(false);

    // Check for a win
    if (checkWin()) {
        QString winner = isXTurn ? "O" : "X";  // The winner is the opposite of the current turn
        if (winner == "X") {
            if (isMultiPlayer) {
                ++player1Wins;
                ui->player_1_wins->setText(QString::number(player1Wins));
            } else {
                ++player1_single_Wins;
                ui->player_1_wins->setText(QString::number(player1_single_Wins));
            }
        } else {
            if (isMultiPlayer) {
                ++player2Wins;
                ui->player_2_wins->setText(QString::number(player2Wins));
            } else {
                ++computer_Wins;
                ui->player_2_wins->setText(QString::number(computer_Wins));
            }
        }
        resetGame();  // Reset the game for a new round
        return;
    }

    // Check for a draw
    if (isDraw()) {
        if (isMultiPlayer) {
            ++tieTimes;
            ui->Tie_Times->setText(QString::number(tieTimes));
        } else {
            ++tie_single_Times;
            ui->Tie_Times->setText(QString::number(tie_single_Times));
        }
        resetGame();  // Reset the game for a new round
    }

    // If it's single-player mode and it's Player O's turn, make a random move
    if (!isMultiPlayer && !isXTurn) {
        RandomPlayer();

        // Recheck the win condition after the random move
        if (checkWin()) {
            QString winner = isXTurn ? "O" : "X";  // The winner is the opposite of the current turn
            if (winner == "X") {
                ++player1_single_Wins;
                ui->player_1_wins->setText(QString::number(player1_single_Wins));
            } else {
                ++computer_Wins;
                ui->player_2_wins->setText(QString::number(computer_Wins));
            }
            resetGame();  // Reset the game for a new round
            return;
        }

        // Check for a draw
        if (isDraw()) {
            ++tie_single_Times;
            ui->Tie_Times->setText(QString::number(tie_single_Times));
            resetGame();  // Reset the game for a new round
        }
    }
}


bool MainWindow::checkWin()
{
    // Horizontal checks
    if (ui->pushButton_2->text() == ui->pushButton_3->text() && ui->pushButton_3->text() == ui->pushButton_4->text() && !ui->pushButton_2->text().isEmpty()) {
        return true;
    }
    if (ui->pushButton_5->text() == ui->pushButton_6->text() && ui->pushButton_6->text() == ui->pushButton_7->text() && !ui->pushButton_6->text().isEmpty()) {
        return true;
    }
    if (ui->pushButton_6->text() == ui->pushButton_7->text() && ui->pushButton_7->text() == ui->pushButton_8->text() && !ui->pushButton_7->text().isEmpty()) {
        return true;
    }
    if (ui->pushButton_7->text() == ui->pushButton_8->text() && ui->pushButton_8->text() == ui->pushButton_9->text() && !ui->pushButton_8->text().isEmpty()) {
        return true;
    }

    // Vertical checks
    if (ui->pushButton_1->text() == ui->pushButton_3->text() && ui->pushButton_3->text() == ui->pushButton_7->text() && !ui->pushButton_1->text().isEmpty()) {
        return true;
    }

    // Diagonal checks
    if (ui->pushButton_1->text() == ui->pushButton_2->text() && ui->pushButton_2->text() == ui->pushButton_5->text() && !ui->pushButton_1->text().isEmpty()) {
        return true;
    }
    if (ui->pushButton_1->text() == ui->pushButton_4->text() && ui->pushButton_4->text() == ui->pushButton_9->text() && !ui->pushButton_1->text().isEmpty()) {
        return true;
    }

    return false;
}

bool MainWindow::isDraw()
{
    for (int i = 1; i <= 10; ++i) {
        QPushButton* button = findChild<QPushButton*>("pushButton_" + QString::number(i));
        if (button && button->text().isEmpty()) {
            return false;  // If any button is empty, it's not a draw
        }
    }
    return true;  // All buttons are filled, and no winner
}

void MainWindow::resetGame()
{
    // Reset all buttons to empty text and re-enable them
    for (int i = 1; i <= 10; ++i) {
        QPushButton* button = findChild<QPushButton*>("pushButton_" + QString::number(i));
        if (button) {
            button->setText("");
            button->setEnabled(true);
        }
    }
    isXTurn = true;  // Start with 'X' again
}

void MainWindow::RandomPlayer()
{
    // Seed the random generator (if not already done elsewhere in your program)
    srand(static_cast<unsigned int>(time(0)));

    // Keep trying until an empty button is found
    while (true) {
        int randomIndex = rand() % 9 + 1; // Random number between 1 and 9
        QPushButton* button = findChild<QPushButton*>("pushButton_" + QString::number(randomIndex));

        // If the button is empty, place 'O' and disable it
        if (button && button->text().isEmpty()) {
            button->setText("O");
            button->setEnabled(false);
            isXTurn = true; // Pass the turn back to player
            return;
        }
    }
}

void MainWindow::resetScores()
{
    if (isMultiPlayer) {
        // Reset multiplayer scores
        player1Wins = 0;
        player2Wins = 0;
        tieTimes = 0;

        // Update the UI with reset scores
        ui->player_1_wins->setText(QString::number(player1Wins));
        ui->player_2_wins->setText(QString::number(player2Wins));
        ui->Tie_Times->setText(QString::number(tieTimes));
    } else {
        // Reset single-player scores
        player1_single_Wins = 0;
        computer_Wins = 0;
        tie_single_Times = 0;

        // Update the UI with reset scores
        ui->player_1_wins->setText(QString::number(player1_single_Wins));
        ui->player_2_wins->setText(QString::number(computer_Wins));
        ui->Tie_Times->setText(QString::number(tie_single_Times));
    }
}

void MainWindow::ResetScoreButtonClicked()
{
    // Call the resetScores function when the button is clicked
    resetScores();
}

