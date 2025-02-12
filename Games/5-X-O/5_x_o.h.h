#ifndef _5_X_O_H
#define _5_X_O_H

#include "BoardGame_Classes.h.h"

char checked_arr[5][5];
int count = 0, counter1 = 0, counter2 = 0;

template <typename T>
class X_O_Board:public Board<T> {
public:
    X_O_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class X_O_Player : public Player<T> {
public:
    static Player<T>** Ptr;
    static void Set_ptr(Player<T>** P);
    X_O_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T>{
public:
    X_O_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};

class UI_5_X_O{
    public:
        void main_5_X_O();
};







//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for X_O_Board
template <typename T>
X_O_Board<T>::X_O_Board() {
    this->rows = this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool X_O_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        checked_arr[x][y] = 'm';

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void X_O_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            if(checked_arr[i][j] == 0){
                if(j != 0){
                    cout << " ";
                }
                cout << "(" << i << "," << j << ")" << " |";;
            }
            else{
                cout << setw(2) << this->board[i][j] << "  |";
            }
            
        }
        cout << "\n------------------------------------------";
    }
    cout << endl;
    cout << " Count: " << this->n_moves << endl;
}

// Returns true if there is any winner
template <typename T>
bool X_O_Board<T>::is_win() {
    count++;
    for (int i = 0; i < this->rows; i++) {
        // Check rows
        if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] &&
            this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4] &&
            this->board[i][0] != 0) {
            if (count % 2 == 0) {
                counter1++;
            } else {
                counter2++;
            }
            }

        // Check columns
        if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] &&
            this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i] &&
            this->board[0][i] != 0) {
            if (count % 2 == 0) {
                counter1++;
            } else {
                counter2++;
            }
            }
    }

    // Check main diagonal
    if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] &&
        this->board[2][2] == this->board[3][3] && this->board[3][3] == this->board[4][4] &&
        this->board[0][0] != 0) {
        if (count % 2 == 0) {
            counter1++;
        } else {
            counter2++;
        }
        }

    // Check anti-diagonal
    if (this->board[0][4] == this->board[1][3] && this->board[1][3] == this->board[2][2] &&
        this->board[2][2] == this->board[3][1] && this->board[3][1] == this->board[4][0] &&
        this->board[0][4] != 0) {
        if (count % 2 == 0) {
            counter1++;
        } else {
            counter2++;
        }
        }


 if(this->n_moves == 24) {
     if(counter1 > counter2) {
         X_O_Player<T>::Ptr[1] = X_O_Player<T>::Ptr[0];
         return true; 
     }else if(counter2 < counter1) {
        X_O_Player<T>::Ptr[0] = X_O_Player<T>::Ptr[1]; 
         return true;
     }
 }
    return false;
}
template <typename T>
bool X_O_Board<T>::is_draw() {
    return (this->n_moves == 25 && !is_win());
}

template <typename T>
bool X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for X_O_Random_Player
template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 5;  // Random number between 0 and 2
    y = rand() % 5;
}

template <typename T>
void X_O_Player<T>::Set_ptr(Player<T>** P){
   X_O_Player<T>::Ptr = P;
}

template <typename T>
Player<T>** X_O_Player<T>::Ptr = nullptr;  // Or some other default value


void UI_5_X_O::main_5_X_O(){
    int choice;
    Player<char>* players[2];
    X_O_Player<char>::Set_ptr(players);
    X_O_Board<char>* B = new X_O_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI X-O Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new X_O_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new X_O_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return ;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new X_O_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new X_O_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return ;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}









#endif // 5_X_O_h