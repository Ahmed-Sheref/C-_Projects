#include "Misere.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
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
Misere_Board<T>::Misere_Board(){
    this->rows = 3;
    this->columns = 3;
    this->board = new char*[this->rows];
    for(int i = 0 ; i < this->rows ; i++){
        this->board[i] = new char[this->columns];
        for(int j = 0 ; j < this->columns ; j++){
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Misere_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == ' '|| mark == ' ')) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Misere_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T>
bool Misere_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != ' ') ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != ' ')) {
            if(this->board[i][0] == 'X' || this->board[0][i]  == 'X'){
                // Cast Player<char>* to Misere_Player<char>* and swap names
                Misere_Player<T>::swap_names(static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[0]),
                                              static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[1]));
                return true;
            }
            else{
                Misere_Player<T>::swap_names(static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[1]),
                                              static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[0]));
                return true;
            }
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != ' ') ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != ' ')) {
        if(this->board[0][0] == 'X' || this->board[0][2]  == 'X'){
            Misere_Player<T>::swap_names(static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[0]),
                                          static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[1]));
            return true;
        }
        else{
            Misere_Player<T>::swap_names(static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[1]),
                                          static_cast<Misere_Player<T>*>(Misere_Player<T>::Ptr[0]));
            return true;
        }
    }

    return false;
}


template <typename T>
bool Misere_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Misere_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
void Misere_Player<T>:: Set_ptr(Player<T>** P){
    Misere_Player<T>::Ptr = P;
}

template <typename T>
Player<T>** Misere_Player<T>::Ptr = nullptr;  

template <typename T>
void Misere_Player<T>::swap_names(Misere_Player<T>* p1, Misere_Player<T>* p2) {
    string temp = p1->getname();  // Get name of the first player
    p1->setname(p2->getname());   // Set name of the first player to second player's name
    p2->setname(temp);            // Set name of the second player to the first player's name
}

template <typename T>
void Misere_Player<T>::setname(const string& new_name) {
    this->name = new_name;
}




template <typename T>
Misere_Player<T>::Misere_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Misere_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
    cin.ignore();
}

// Constructor for X_O_Random_Player
template <typename T>
Misere_RandomPlayer<T>::Misere_RandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Misere_RandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}

void UI_Misere::Main_Program(){

  int choice;
    Player<char>* players[2];
    Misere_Player<char>::Set_ptr(players);
    Misere_Board<char>* B = new Misere_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to Misere Tic-Tac-Toe Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new Misere_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new Misere_RandomPlayer<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
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
            players[1] = new Misere_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new Misere_RandomPlayer<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
    }

    // Create the game manager and run the game
    GameManager<char> misere_game(B, players);
    misere_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}




