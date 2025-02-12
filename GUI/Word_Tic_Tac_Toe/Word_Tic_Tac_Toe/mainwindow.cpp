#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <fstream>
#include <QMessageBox>
#include <QDir>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
    connect(ui->Reset_score, &QPushButton::clicked, this, &MainWindow::resetScores);

    // Initialize selectedButton as nullptr
    selectedButton = nullptr;

    // Enable focus on the main window to capture keyboard events
    this->setFocusPolicy(Qt::StrongFocus);
    Default_dic();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked() {
    // Determine which button was clicked
    selectedButton = qobject_cast<QPushButton*>(sender());
    if (selectedButton) {
        selectedButton->setFocus(); // Ensure the clicked button gets focus
    }
}

// Capture keyboard input
void MainWindow::keyPressEvent(QKeyEvent *event) {
    // Check if a button is selected
    if (selectedButton == nullptr) return;

    // Get the key input as a QChar
    QChar key = event->text().at(0); // Get the first character from the key press

    // Check if the key is a letter (alphabet)
    if (key.isLetter()) {
        key = key.toUpper();

        if (player == 2) {  // Player 2's turn (second player)
            selectedButton->setStyleSheet(
                "font-family: 'Comic Sans MS';"
                "background-color: #000000; /* Black background */"
                "border: 2px solid #FFFFFF; /* White border */"
                "font-size: 36px;"
                "font-weight: bold;"
                "color: #2596be;"
                "text-align: center;"
                "padding: 0;"
                "margin: 0;"
                );
            selectedButton->setText(key); // Set the button's text to the key pressed
            selectedButton->setEnabled(false); // Disable the button after it's used
            player = 1;  // Switch to player 1
        }
        else if (player == 1) {  // Player 1's turn
            selectedButton->setStyleSheet(
                "font-family: 'Comic Sans MS';"
                "background-color: #000000; /* Black background */"
                "border: 2px solid #FFFFFF; /* White border */"
                "font-size: 36px;"
                "font-weight: bold;"
                "color: orange;"  // Player 1's color
                "text-align: center;"
                "padding: 0;"
                "margin: 0;"
                );
            selectedButton->setText(key); // Set the button's text to the key pressed
            selectedButton->setEnabled(false); // Disable the button after it's used
            player = 2;  // Switch to player 2
        }

        selectedButton = nullptr;  // Clear the selected button after setting the text
    }

    if (is_win()){
        if (player == 2){  // Player 1 wins
            if (isMultiPlayer){
                ++player1Wins;
                ui->player_1_wins->setText(QString::number(player1Wins));
            }
            else{
                    ++player1_single_Wins;
                    ui->player_1_wins->setText(QString::number(player1_single_Wins));
            }
        }
        else if (player == 1){  // Player 2 wins
            if (isMultiPlayer) {
                ++player2Wins;
                ui->player_2_wins->setText(QString::number(player2Wins));
            }
            else{
                ++computer_Wins;
                ui->player_2_wins->setText(QString::number(computer_Wins));
            }
        }
        resetGame();  // Reset the game for a new round
        player = 1;   // Reset to player 1's turn
        return;
    }

    // Check for a draw
    if (isDraw()) {
        if (isMultiPlayer) {
            ++tieTimes;
            ui->Tie_Times->setText(QString::number(tieTimes));
        }
        else{
            ++tie_single_Times;
            ui->Tie_Times->setText(QString::number(tie_single_Times));
        }
        resetGame();  // Reset the game for a new round
        player = 1;   // Reset to player 1's turn
    }

    // Single-player mode (AI moves automatically after player 1)
    if (!isMultiPlayer && player == 2) {
        RandomPlayer();  // AI makes its move

        if (is_win()) {
            if (player == 2) {  // Player 1 wins
                if (isMultiPlayer) {
                    ++player1Wins;
                    ui->player_1_wins->setText(QString::number(player1Wins));
                }
                else {
                    ++player1_single_Wins;
                    ui->player_1_wins->setText(QString::number(player1_single_Wins));
                }
            }
            else if (player == 1){  // Player 2 wins
                if (isMultiPlayer){
                    ++player2Wins;
                    ui->player_2_wins->setText(QString::number(player2Wins));
                }
                else{
                    ++computer_Wins;
                    ui->player_2_wins->setText(QString::number(computer_Wins));
                }
            }
            resetGame();  // Reset the game for a new round
            player = 1;   // Reset to player 1's turn
            return;
        }
    }

        // Check for a draw
    if (isDraw()) {
            if (isMultiPlayer) {
                ++tieTimes;
                ui->Tie_Times->setText(QString::number(tieTimes));
            }
            else{
                ++tie_single_Times;
                ui->Tie_Times->setText(QString::number(tie_single_Times));
            }
            resetGame();  // Reset the game for a new round
            player = 1;   // Reset to player 1's turn
    }
}




void MainWindow::Default_dic(){
    ifstream file ("dic.txt");
    Check_dic_status(file);
    string get;
    QString capital;
    while(file >> get){
        for(char c : get){
            capital += QChar(toupper(c));
        }
        Words.push_back(capital);
        capital ="";
    }

}


void MainWindow::Check_dic_status(std::ifstream &file) {
    if (!file) {
        ui->Dic_status->setText("Failed");
        ui->Dic_status->setStyleSheet("color: red;");  // Set the text color to red

        // Show an error message box
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("File Error");
        msgBox.setText("File failed. Make sure you have the dictionary file. Make sure the file is in the correct directory. 'Word_Tic_Tac_Toe->build->Desktop_Qt_6_8_0_MinGW_64_bit-Debug'");

        // Set the message box's stylesheet to change the background to black and text to white
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; }"
                             "QLabel { color : white; }");  // Set font color to white and background to black

        // Show the message box and wait for the user to click "OK"
        int ret = msgBox.exec();

        // Only quit the application if the user clicks "OK"
        if (ret == QMessageBox::Ok) {
            exit(0);
        }
    }
    else {
        ui->Dic_status->setText("Accessed");
        ui->Dic_status->setStyleSheet("color: Green;");  // Set the text color to green
    }
}

bool MainWindow::Search_Word(QString  first_letter , QString  second_letter , QString  third_letter){
    QString  word = first_letter + second_letter  + third_letter;
    for(QString  s : Words){
        if(word == s) return 1;
    }
    return 0;
}

bool MainWindow::is_win(){
    // Check horizontal win
    if(Search_Word(ui->pushButton_1->text(),ui->pushButton_2->text(),ui->pushButton_3->text()) || Search_Word(ui->pushButton_4->text(),ui->pushButton_5->text(),ui->pushButton_6->text())||
        Search_Word(ui->pushButton_7->text(),ui->pushButton_8->text(),ui->pushButton_9->text())){
        return 1;
    }
    // Check vertical win
    if(Search_Word(ui->pushButton_1->text(),ui->pushButton_4->text(),ui->pushButton_7->text()) || Search_Word(ui->pushButton_2->text(),ui->pushButton_5->text(),ui->pushButton_8->text())||
        Search_Word(ui->pushButton_3->text(),ui->pushButton_6->text(),ui->pushButton_9->text()) ){
        return 1;
    }
    // Check diagonal win
    if(Search_Word(ui->pushButton_1->text(),ui->pushButton_5->text(),ui->pushButton_9->text()) || Search_Word(ui->pushButton_3->text(),ui->pushButton_5->text(),ui->pushButton_7->text()) ) return 1;

    return 0; // No win detected
}

bool MainWindow::isDraw()
{
    for (int i = 1; i <= 9; ++i) {
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
    for (int i = 1; i <= 9; ++i) {
        QPushButton* button = findChild<QPushButton*>("pushButton_" + QString::number(i));
        if (button) {
            button->setText("");
            button->setEnabled(true);
        }
    }
    player = 1;  // Start with player1 again

}

void MainWindow::RandomPlayer()
{
    // Seed the random generator (if not already done elsewhere in your program)
    srand(static_cast<unsigned int>(time(0)));

    // Keep trying until an empty button is found
    while (true) {
        int randomIndex = rand() % 9 + 1; // Random number between 1 and 9
        QPushButton* button = findChild<QPushButton*>("pushButton_" + QString::number(randomIndex));
        QString rand_char;
        rand_char = QChar('A' + (rand() % 26));

        if (button && button->text().isEmpty()) {
            button->setText(rand_char);
            button->setStyleSheet(
                "font-family: 'Comic Sans MS';"
                "background-color: #000000; /* Black background */"
                "border: 2px solid #FFFFFF; /* White border */"
                "font-size: 36px;"
                "font-weight: bold;"
                "color: #2596be;"
                "text-align: center;"
                "padding: 0;"
                "margin: 0;"
                );
            button->setEnabled(false);
            player = 1; // Pass the turn back to player
            return;
        }
    }
}

void MainWindow::setSinglePlayerMode()
{
    // Set game mode to single-player (one player vs AI)
    isMultiPlayer = false;
    ui->player_2->setText("Computer (🔵)");
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
    ui->player_2->setText("Player 2 (🔵)");
    ui->Game_mode->setText("Multiplayer");

    // Update the UI with the current multiplayer scores
    ui->player_1_wins->setText(QString::number(player1Wins));
    ui->player_2_wins->setText(QString::number(player2Wins));
    ui->Tie_Times->setText(QString::number(tieTimes));

    resetGame();  // Reset game state when switching mode
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






