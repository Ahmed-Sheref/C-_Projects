#include "Sus_1.h"
#include <iostream>
#include <vector>
#include <fstream>
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
Sus_Board<T>::Sus_Board(){
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
bool Sus_Board<T>::update_board(int x, int y, T mark){
    if (x < 0 || x >= this->rows) {
        if(is_computer){
            return false;
        }
        cout << RED << "Invalid move: Row " << x << " is out of bounds." << RESET << endl;
        return false;
    }
    if (y < 0 || y >= this->columns) {
        if(is_computer){
            return false;
        }
        cout << RED <<"Invalid move: Column " << y << " is out of bounds for row " << x << "." << RESET << endl;
        return false;
    }
    if (this->board[x][y] != ' ') {
         if(is_computer){
            return false;
        }
        cout << RED << "Invalid move: Cell (" << x << ", " << y << ") is already occupied." << RESET << endl;
        return false;
    }
     // Update the board
    this->board[x][y] = toupper(mark);
    this->n_moves++;
    return true;
}

template <typename T>
void Sus_Board<T>::display_board(){
    int rows = 0;
    Get_Sus(player_1_wins, player_2_wins, counter);
    cout << "     0     1     2\n";
     int r = 0;
    for(int m = 0 ; m < 3 ; m++){
        cout << "  ";
        for(int i = 0 ; i < 3 ; i++ ){
            cout << "+-----";
        }
        cout << "+" << endl;
        for(int i = 0 ; i < 3 ; i++){
            if(i == 0){
                cout << rows << " ";
                rows++;
            }
            cout <<"|  " << this->board[r][i] << "  ";
        }
        cout << "|";
        if(m == 1){
            cout <<"   "<<player_1_nm <<" : " << player_1_wins << "   |  " << player_2_nm << " : " << player_2_wins; 
        }
        cout << endl;
        
        r++;
    }
    cout << "  ";
    for(int i = 0 ; i < 3 ; i++ ){
            cout << "+-----";
    }
        cout << "+" << endl;
}

template <typename T>
bool Sus_Board<T>::check_Word(char first_letter , char second_letter , char third_letter){
    string word = {first_letter, second_letter, third_letter};
    if(word == "SUS"){
        return 1;
    }
    return 0;
}

template <typename T>
bool Sus_Board<T>::is_win() {
    if (this->n_moves == 9 || no_more_SUS_possible) {
        // Check if player 1 wins
        if (player_1_wins > player_2_wins) {
            Sus_Player<T>::Ptr[1] = Sus_Player<T>::Ptr[0];  // Assign player 1 to player 2
            return true;
        }
        // Check if player 2 wins
        else if (player_1_wins < player_2_wins) {
            Sus_Player<T>::Ptr[0] = Sus_Player<T>::Ptr[1];  // Assign player 2 to player 1
            return true;
        }
    }
    return false;
}

template <typename T>
bool Sus_Board<T>::is_draw(){
    if (this->n_moves == 9 || no_more_SUS_possible ){
        player_1_wins == player_2_wins;
        return 1;
    }
    return 0;
}

template <typename T>
bool Sus_Board<T>::game_is_over(){
    return is_win() || is_draw() || no_more_SUS_possible;
}


template <typename T>
char Sus_Board<T>::getCell(int x , int y){
    return this->board[x][y];  
}


template <typename T>
void Sus_Board<T>::Get_Sus(int& p1_wins, int& p2_wins, int counter) {
    int total_pts = 0;
    bool found = false;
    no_more_SUS_possible = true;

    // Check horizontal win (row by row)
    for (int i = 0; i < 3; ++i) {
        if (!checked_rows[i] && check_Word(this->board[i][0], this->board[i][1], this->board[i][2])) {
            found = true;
            total_pts++;
            checked_rows[i] = true; // Mark this row as checked
        }

        // Check if "SUS" can still be completed
        if (can_complete_sus(this->board[i][0], this->board[i][1], this->board[i][2])) {
            no_more_SUS_possible = false; // At least one "SUS" is still possible
        }
    }

    // Check vertical win (column by column)
    for (int j = 0; j < 3; ++j) {
        if (!checked_cols[j] && check_Word(this->board[0][j], this->board[1][j], this->board[2][j])) {
            found = true;
            total_pts++;
            checked_cols[j] = true; // Mark this column as checked
        }

        // Check if "SUS" can still be completed
        if (can_complete_sus(this->board[0][j], this->board[1][j], this->board[2][j])) {
            no_more_SUS_possible = false; // At least one "SUS" is still possible
        }
    }

    // Check diagonal win (top-left to bottom-right)
    if (!checked_diagonals[0] && check_Word(this->board[0][0], this->board[1][1], this->board[2][2])) {
        found = true;
        total_pts++;
        checked_diagonals[0] = true; // Mark this diagonal as checked
    }
    if (can_complete_sus(this->board[0][0], this->board[1][1], this->board[2][2])) {
        no_more_SUS_possible = false; // At least one "SUS" is still possible
    }

    // Check diagonal win (top-right to bottom-left)
    if (!checked_diagonals[1] && check_Word(this->board[0][2], this->board[1][1], this->board[2][0])) {
        found = true;
        total_pts++;
        checked_diagonals[1] = true; // Mark this diagonal as checked
    }
    if (can_complete_sus(this->board[0][2], this->board[1][1], this->board[2][0])) {
        no_more_SUS_possible = false; // At least one "SUS" is still possible
    }

    // Update player wins based on who made the last move
    if (counter % 2 == 0 && found) {
        p1_wins += total_pts;
    } else if (counter % 2 != 0 && found) {
        p2_wins += total_pts;
    }
}

template <typename T>
bool Sus_Board<T>::can_complete_sus(char c1, char c2, char c3) {
    // Skip if the line already forms "SUS"
    if (c1 == 'S' && c2 == 'U' && c3 == 'S') {
        return false; // "SUS" already formed, no need to mark anything
    }

    // Create a potential completion for "S-U-S" without modifying the board
    char temp1 = c1 == ' ' ? 'S' : c1;
    char temp2 = c2 == ' ' ? 'U' : c2;
    char temp3 = c3 == ' ' ? 'S' : c3;

    // Check if completing this forms "SUS"
    string word = {temp1, temp2, temp3};
    return (word == "SUS"); // Return whether this line can form "SUS"
}



template <typename T>
Sus_Player<T>::Sus_Player(string n , T sy) : Player<T>(n , sy){}

template <typename T>
void Sus_Player<T>::getmove(int& x, int& y){
    if(this->getname() != last_player){
        counter++;
    }
    cout <<"\nPlease Enter your move x and y (X = Row , Y = column) separated by spaces: ";
    cin >> x >> y;
    cin.ignore();
    last_player = this->getname();

}


template <typename T>
void Sus_Player<T>::Set_ptr(Player<T>** P){
    Sus_Player<T>::Ptr = P;
}

template <typename T>
Player<T>** Sus_Player<T>::Ptr = nullptr;  // Or some other default value




template <typename T>
Sus_RandomPlayer<T>::Sus_RandomPlayer(T sy) : RandomPlayer<T>(sy){
     this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); 
}

template <typename T>
void Sus_RandomPlayer<T>::getmove(int& x, int& y){
    x = rand() % 3;
    y = rand() % 3;
}





void UI_Sus::Main_Program(){
        char c1 , c2;
        string choice;
        Player<char>* players[2];
        Sus_Player<char>::Set_ptr(players);
        Sus_Board<char>* B = new Sus_Board<char>();
        string player1Name, player2Name;
        cout << "===============================================================\n\n";
        cout << YELLOW <<"                    Welcome to the SUS Game!\n" << RESET;
        cout << "           A fun twist on the classic Tic-Tac-Toe game \n";
        cout << "                        with a word-style challenge!\n\n";
        cout << "                     Controls:\n";
        cout << "                     1. Enter the row (X)\n";
        cout << "                     2. Enter the column (Y)\n";
        cout << "                     3. Try to create as many \"S-U-S\" sequences\n";
        cout << "                        as possible in a row to WIN!\n\n";
        cout << "          Ready to test your strategy and luck? 🎮\n\n";
        cout << "===============================================================\n\n";
        cout << "Enter Player 1 name: ";
        getline(cin,player1Name);
        player_1_nm = player1Name;
        while(true){
            string choose_letter;
            cout << "Please Choose which letter u want to start with \n";
            cout << "1) S\n";
            cout << "2) U\n";
            getline(cin,choose_letter);
            if(choose_letter == "1" || choose_letter == "s" || choose_letter == "S"){
                c1 ='S';
                c2 = 'U';
                break;
            }
            else if(choose_letter == "2"|| choose_letter == "u" || choose_letter == "U"){
                c1 = 'U';
                c2 = 'S';
                break;
            }
            else{
                cout << RED << "Invalid choice, Please Choose S or U" << RESET << endl;
            }
        }
        while (true){
            cout << "Choose Player 1 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            getline(cin,choice);
            if(choice == "1"){
                players[0] = new Sus_Player<char>(player1Name, c1);
                break;
            }
            else if(choice == "2"){
                players[0] = new Sus_RandomPlayer<char>(c1);
                is_computer = true;
                player_1_nm = "Computer";
                break;
            }
            else{
                cout << RED << "Invalid choice for Player 1." << RESET << endl;
                continue;
            }

        }
       
       
        
        // Set up player 2
        cout << "Enter Player 2 name: ";
        getline(cin,player2Name);
        player_2_nm = player2Name;
        while(true){
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            getline(cin,choice);

            if(choice == "1"){
                players[1] = new Sus_Player<char>(player2Name, c2);
                break;
            }
            else if(choice == "2"){
                players[1] = new Sus_RandomPlayer<char>(c2);
                is_computer = true;
                player_2_nm = "Computer";
                break;
            }
            else{
                cout << RED << "Invalid choice for Player 2." << RESET << endl;
                continue;
            }
        }

        // Create the game manager and run the game
        GameManager<char> word_tic_tac_game(B, players);
        word_tic_tac_game.run();

        // Clean up
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

}
