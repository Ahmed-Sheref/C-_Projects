#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_c1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_c2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_c3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_c4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_c5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_c6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_c7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(resett()));
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::setSinglePlayerMode);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::setMultiPlayerMode);
    // connect(ui->pushButton, SIGNAL(released()), this, SLOT(digit_pressed()));
    // connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resett()
{
    resetBoard();
}

void MainWindow::setSinglePlayerMode()
{
    // Set game mode to single-player (one player vs AI)
    is_MultiPlayer = false;
    ui->label_3->setText("Computer (🟠)");
    ui->label_5->setText("Single Player");


    // resetBoard();  // Reset game state when switching mode
}

void MainWindow::setMultiPlayerMode()
{
    // Set game mode to multiplayer (two human players)
    is_MultiPlayer = true;
    ui->label_3->setText("Player 2 (🟠)");
    ui->label_5->setText("Multiplayer");

    // Update the UI with the current multiplayer scores


    /*resetBoard(); */ // Reset game state when switching mode
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString colum_s = button->text();
    int column = colum_s.toInt();
    Update_Board(column - 1);
    if (!is_MultiPlayer) makeRandomMove();
    if(is_win())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information); // Set the warning icon
        msgBox.setWindowTitle("Winner");
        if (is_MultiPlayer) {
            if (is_Player_1) {
                msgBox.setText("Player 2 won");
            } else {
                msgBox.setText("Player 1 won");
            }
        } else {
            // Single-player mode (against the computer)
            if (is_Player_1) {
                msgBox.setText("Computer won");
            } else {
                msgBox.setText("Player 1 won");
            }
        }

        // Set the custom stylesheet for the message box
        msgBox.setStyleSheet(
            "QMessageBox { background-color: black; color: white; }" // Background and text color
            "QLabel { color: white; font-size: 14px; }"              // Label styling for the message
            "QPushButton { background-color: gray; color: white; font-size: 12px; }" // Button styling
            );

        msgBox.exec();
        resetBoard();
    }



}

void MainWindow::Update_Board(int column)
{
    int lastRow = ui->Board->rowCount() - 1;

    // Declare row_to_place
    int row_to_place = -1;

    // Iterate through the rows from bottom to top
    for (int i = lastRow; i >= 0; i--) {
        QTableWidgetItem* item = ui->Board->item(i, column); // Get the item at (i, column)

        // Check if the cell is empty
        if (!item || item->text().isEmpty()) {
            row_to_place = i;
            break; // Stop at the first empty cell
        }
    }

    // If no empty row was found, the column is full
    if (row_to_place == -1) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning); // Set the warning icon
        msgBox.setWindowTitle("Column Full");
        msgBox.setText("This column is full! Choose another column.");

        // Set the custom stylesheet for the message box
        msgBox.setStyleSheet(
            "QMessageBox { background-color: black; color: white; }" // Background and text color
            "QLabel { color: white; font-size: 14px; }"              // Label styling for the message
            "QPushButton { background-color: gray; color: white; font-size: 12px; }" // Button styling
            );

        msgBox.exec(); // Show the message box
        return;
    }



    if (is_Player_1)
    {
        QTableWidgetItem* newItem = new QTableWidgetItem("🔵");
        newItem->setTextAlignment(Qt::AlignCenter);
        ui->Board->setItem(row_to_place, column, newItem);
        is_Player_1 = false;
    }
    else
    {
        QTableWidgetItem* newItem = new QTableWidgetItem("🟠");
        newItem->setTextAlignment(Qt::AlignCenter);
        ui->Board->setItem(row_to_place, column, newItem);
        is_Player_1 = true;
    }

}

bool MainWindow::is_win() {
    // Check horizontal winner
    for (int r = 0; r < 6; ++r) {
        for (int c = 0; c < 7 - 3; ++c) { // Ensure there are 4 columns to check
            QTableWidgetItem* item1 = ui->Board->item(r, c);
            QTableWidgetItem* item2 = ui->Board->item(r, c + 1);
            QTableWidgetItem* item3 = ui->Board->item(r, c + 2);
            QTableWidgetItem* item4 = ui->Board->item(r, c + 3);

            if (item1 && item2 && item3 && item4 &&
                !item1->text().isEmpty() && // Check if not empty
                item1->text() == item2->text() &&
                item1->text() == item3->text() &&
                item1->text() == item4->text()) {
                return true;
            }
        }
    }

    // Check vertical (column) winner
    for (int c = 0; c < 7; ++c) {
        for (int r = 0; r < 6 - 3; ++r) { // Ensure there are 4 rows to check
            QTableWidgetItem* item1 = ui->Board->item(r, c);
            QTableWidgetItem* item2 = ui->Board->item(r + 1, c);
            QTableWidgetItem* item3 = ui->Board->item(r + 2, c);
            QTableWidgetItem* item4 = ui->Board->item(r + 3, c);

            if (item1 && item2 && item3 && item4 &&
                !item1->text().isEmpty() &&
                item1->text() == item2->text() &&
                item1->text() == item3->text() &&
                item1->text() == item4->text()) {
                return true;
            }
        }
    }

    // Check diagonal (down-right) winner
    for (int r = 0; r < 6 - 3; ++r) { // Ensure there is enough space for diagonal checks
        for (int c = 0; c < 7 - 3; ++c) {
            QTableWidgetItem* item1 = ui->Board->item(r, c);
            QTableWidgetItem* item2 = ui->Board->item(r + 1, c + 1);
            QTableWidgetItem* item3 = ui->Board->item(r + 2, c + 2);
            QTableWidgetItem* item4 = ui->Board->item(r + 3, c + 3);

            if (item1 && item2 && item3 && item4 &&
                !item1->text().isEmpty() &&
                item1->text() == item2->text() &&
                item1->text() == item3->text() &&
                item1->text() == item4->text()) {
                return true;
            }
        }
    }

    // Check diagonal (up-right) winner
    for (int r = 3; r < 6; ++r) { // Start from row 3 to ensure enough space for up-right diagonal
        for (int c = 0; c < 7 - 3; ++c) {
            QTableWidgetItem* item1 = ui->Board->item(r, c);
            QTableWidgetItem* item2 = ui->Board->item(r - 1, c + 1);
            QTableWidgetItem* item3 = ui->Board->item(r - 2, c + 2);
            QTableWidgetItem* item4 = ui->Board->item(r - 3, c + 3);

            if (item1 && item2 && item3 && item4 &&
                !item1->text().isEmpty() &&
                item1->text() == item2->text() &&
                item1->text() == item3->text() &&
                item1->text() == item4->text()) {
                return true;
            }
        }
    }

    return false; // No winner found
}

void MainWindow::resetBoard() {
    // Loop through all rows and columns of the QTableWidget (assumed 6 rows and 7 columns)
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            QTableWidgetItem* item = ui->Board->item(row, col);
            if (item) {
                item->setText("");  // Clear the text (or symbol) in each cell
                item->setBackground(QBrush(Qt::white)); // Optional: Reset background to white
            }
        }
    }

    // Optionally, reset any game-related flags
    is_Player_1 = true;  // Start with Player 1's turn
    // You can add more variables to reset if needed, such as the game state or move count.

    // (Optional) Set any other UI elements back to their initial state, such as score displays.
}

bool MainWindow::is_draw()
{
    int result = 0;  // Initialize result to 0

    // Loop through each row and column of the QTableWidget (Board)
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            QTableWidgetItem* item = ui->Board->item(row, col);

            // Ensure the item exists and check if the cell is filled (not empty)
            if (item && !item->text().isEmpty()) {
                result += 1;  // Increment the counter for filled cells
            }
        }
    }

    // If all 42 cells are filled (6 rows * 7 columns = 42 cells), it's a draw
    if (result == 42) {
        QMessageBox::information(this, "Game Over", "*** Draw ***");
        return true;
    }

    return false;
}

#include <QMessageBox>
#include <QTableWidgetItem>
#include <cstdlib>  // For rand()

// Function to handle the random move
void MainWindow::makeRandomMove() {
    bool valid_move = false;
    int column = -1;  // Column to place the piece in
    int row_to_place = -1; // Row where the piece will be placed

    // Randomly select a column (0 to 6)
    while (!valid_move)
    {
        column = rand() % 7; // Randomly select a column between 0 and 6

        // Check if the column is full by iterating from the bottom row
        for (int row = ui->Board->rowCount() - 1; row >= 0; --row)
        {
            QTableWidgetItem* item = ui->Board->item(row, column); // Get the item at (row, column)

            // Check if the cell is empty
            if (!item || item->text().isEmpty()) {
                row_to_place = row; // The piece will be placed here
                valid_move = true;  // Found a valid spot
                break;
            }
        }


    }


    if (valid_move) {
        QTableWidgetItem* newItem;
            // newItem = new QTableWidgetItem("🔵"); // Player 1's piece
            // is_Player_1 = false;  // Switch to Player 2
            newItem = new QTableWidgetItem("🟠"); // Player 2's piece
            is_Player_1 = true;   // Switch to Player 1

        newItem->setTextAlignment(Qt::AlignCenter); // Center the piece
        ui->Board->setItem(row_to_place, column, newItem); // Place the piece in the board
    }
}







