#include "Pyramid_X_O.h"
#include <iostream>
using namespace std;

// Color codes (define macros)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

template <typename T>

Pyramid_X_O_Board<T>::Pyramid_X_O_Board(){
    this->rows = 3;
    this->columns = 1;
    this->board = new char*[this->rows];
    for(int i = 0 ; i < this->rows ; i++){
        this->board[i] = new char[this->columns];
        for(int j = 0 ; j < this->columns ; j++){
            this->board[i][j] = ' ';
        }
        this->columns += 2;
    }
    this->n_moves = 0;
}

template <typename T>

bool Pyramid_X_O_Board<T>::update_board(int x, int y, T mark){
    if (x < 0 || x >= this->rows) {
        cout << RED << "Invalid move: Row " << x << " is out of bounds." << RESET << endl;
        return false;
    }
    int max_columns = 1 + 2 * x; // Columns increase by 2 with each row
    if (y < 0 || y >= max_columns) {
        cout << RED <<"Invalid move: Column " << y << " is out of bounds for row " << x << "." << RESET << endl;
        return false;
    }
    if (this->board[x][y] != ' ') {
        cout << RED << "Invalid move: Cell (" << x << ", " << y << ") is already occupied." << RESET << endl;
        return false;
    }
    // Update the board
    this->board[x][y] = toupper(mark);
    this->n_moves++;
    return true;
}

template <typename T>

void Pyramid_X_O_Board<T>::display_board(){
    this->columns = 1;
    int y = 8; 
    for (int i = 0; i < 3; i++) {
        if(i == 2){
            y=0;
        }
        else if(i == 1){
            y=4;
        }
        for (int k = 0; k < y; k++) {
            cout << " ";
        }

        for (int j = 0; j < this->columns; j++) {
            cout << "+---";
        }
        cout << "+" << endl;

        for (int k = 0; k < y; k++) {
            cout << " ";
        }
        for (int j = 0; j < this->columns; j++) {
            cout << "| " << this->board[i][j] << " ";
        }
        cout << "|" << endl;

        this->columns += 2;
        y -= 2;
    }

    for (int k = 0; k < y + 2; k++) {
        cout << " ";
    }
    for (int j = 0; j < this->columns - 2; j++) {
        cout << "+---";
    }
    cout << "+" << endl;

}

template <typename T>
bool Pyramid_X_O_Board<T>::is_win(){
    // Check horizontal win
    if ((this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2] && this->board[1][0] != ' ') ||
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != ' ') ||
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][1] != ' ') ||
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != ' ')) {
        return 1;
    }

    // Check vertical win
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != ' ')) {
        return 1;
    }

    // Check diagonal win
    if ((this->board[0][0] == this->board[1][2] && this->board[1][2] == this->board[2][4] && this->board[0][0] != ' ') ||
        (this->board[2][0] == this->board[1][0] && this->board[1][0] == this->board[0][0] && this->board[2][0] != ' ')) {
        return 1;
    }

    return 0; // No win detected
}

template <typename T>
bool Pyramid_X_O_Board<T>::is_draw(){
    if (this->n_moves == 9 && !is_win()) return 1;
    else return 0;
}

template <typename T>
bool Pyramid_X_O_Board<T>::game_is_over(){
    return is_win() || is_draw();
}

template <typename T>
Pyramid_X_O_Player<T>::Pyramid_X_O_Player(string n , T sy ) : Player<T>(n, sy){}

template <typename T>
void Pyramid_X_O_Player<T>::getmove(int& x, int& y , int player_num){
    cout << endl << "Player "<< player_num << " : "<<" Please Enter your move x and y (X = Row , Y = column) separated by spaces: ";
    cin >> x >> y;
    cin.ignore();
}

template <typename T>
Pyramid_X_O_RandomPlayer<T>::Pyramid_X_O_RandomPlayer(T sy) : RandomPlayer<T>(sy){
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); 
}

template <typename T>
void Pyramid_X_O_RandomPlayer<T>::getmove(int& x, int& y, int player_num){
    x = rand() % 3;
    if(x == 0)  y = 0;
    else if (x == 1) y = rand() % 3;
    else if (x == 2) y = rand() % 5;
}



