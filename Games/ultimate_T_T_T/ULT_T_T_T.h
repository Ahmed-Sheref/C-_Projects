#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
using namespace std;

#ifndef ULT_T_T_T_H
#define ULT_T_T_T_H

#pragma once

pair<bool , pair<int , int>> Skip;




template <typename T>
class ULT_T_T_T_Board : public Board<T>
{
    public:
    ULT_T_T_T_Board<char>* small_boards[9];
    ULT_T_T_T_Board();
    bool update_board (int x , int y, T symbol);
    void display_small_board (ULT_T_T_T_Board<char>* s);
    void display_board ();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    bool valid_Board(int x , int y , ULT_T_T_T_Board<T>* b);
    void set_small_board ();
    char** getBoard() 
    {
        return this->board;
    }
    pair <int , int> valid_input(string x , string y);
    static Player<T>** Test_Player;
    static void set_ptr (Player<T>** Test);
    static pair<T,T> symbols;
};
template <typename T>
Player<T>** ULT_T_T_T_Board<T>::Test_Player = nullptr;

template <typename T>
void ULT_T_T_T_Board<T>::set_ptr(Player<T>** Test)
{
    ULT_T_T_T_Board<T>::Test_Player = Test;
}

template <typename T>
ULT_T_T_T_Board<T>::ULT_T_T_T_Board()
{
    this->rows = this->columns = 3;
    this->board = new char*[3];
    for (int i = 0; i < 3; i++)
    {
        this->board[i] = new char[3];
        for (int j = 0; j < 3; j++)
        {
            this->board[i][j] = '#';
        }
    }
    for (int i = 0; i < 9; i++)
    {
        this->small_boards[i] = nullptr;
    }
}
template <typename T>
pair<T,T> ULT_T_T_T_Board<T>::symbols;

template <typename T>
void ULT_T_T_T_Board<T>::set_small_board()
{
    for (int i = 0; i < 9; i++)
    {
        this->small_boards[i] = new ULT_T_T_T_Board<T>();
    }
}


template <typename T>
bool ULT_T_T_T_Board<T>::valid_Board(int x, int y, ULT_T_T_T_Board<T>* b) 
{
    return (b->board[x - 1][y - 1] == '#');
}

template <typename T>
pair <int , int> ULT_T_T_T_Board<T>::valid_input(string x , string y)
{
    string Check_input_X = x;
    string Check_input_y = y;
    while (true)
    {
        if (!all_of(Check_input_X.begin(), Check_input_X.end(), ::isdigit) || !all_of(Check_input_y.begin(), Check_input_y.end(), ::isdigit)) 
        {
            cout << "Please enter a valid (x) , (y) numbers (1-3) -> ex: 1 2\n";
            cin >> Check_input_X;
            cin >> Check_input_y;
            continue;
        }

        int valid_number_x = stoi(Check_input_X);
        int valid_number_y = stoi(Check_input_y);
        if ((valid_number_x >= 1 && valid_number_x <= 3) and (valid_number_y >= 1 && valid_number_y <= 3)) 
        {
            return {valid_number_x,valid_number_y};
        } 
        else 
        {
            cout << "Please enter a valid (x) , (y) numbers (1-3) -> ex: 1 2\n";
            cin >> x >> y;
        }
    }
}

template <typename T>
bool ULT_T_T_T_Board<T>::update_board(int x , int y , T symbol)
{
    pair <int , int> Big_XO = valid_input(to_string(x) , to_string(y));
    int index = (Big_XO.first - 1) * 3 + (Big_XO.second - 1);
    //! if (this->small_boards[index] == nullptr)
    //! {
    //!     this->small_boards[index] = new ULT_T_T_T_Board<T>();
    //! }
    if (this->small_boards[index]->is_draw() || this->small_boards[index]->is_win())
    {
        cout << "This Square is Full or Draw or won\n";
        return false;
    }
    pair <int , int> small_XO;
    this->display_small_board(small_boards[index]);
    int s_x = (Skip.first ? Skip.second.first - 1:  small_XO.first - 1); 
    int s_y = (Skip.first ? Skip.second.second -1:  small_XO.second - 1);
    if (!Skip.first)
    {
        cout << "Please enter a valid (x) , (y) numbers (1-3) -> for small board ex: 1 2\n";
        cin >> small_XO.first >> small_XO.second;
        small_XO = valid_input(to_string(small_XO.first) , to_string(small_XO.second));
        s_x = small_XO.first - 1;
        s_y = small_XO.second -1;
        if (!valid_Board(s_x + 1 , s_y + 1, small_boards[index]))
        {
            cout << "Invalid number Or ((REPEATED) INDEX)... Please again the main index and sub index\n";
            this->display_board();
            return false;
        }
    }
    else
    {
        cout << "Enter the main index by computer -> " << Big_XO.first << ' ' << Big_XO.second << endl;
        cout << "Enter the sub_board by computer  -> " << s_x + 1 << ' ' << s_y + 1<< endl;
    }
    small_boards[index]->board[s_x][s_y] = symbol;
    small_boards[index]->n_moves++;
    if (this->small_boards[index]->is_win())
    {
        this->small_boards[index]->display_small_board(this->small_boards[index]);
        this->board[Big_XO.first - 1][Big_XO.second - 1] = symbol;
        this->n_moves++;
    }
    this->display_small_board(small_boards[index]);
    return true;
}

template <typename T>
void ULT_T_T_T_Board<T>::display_small_board(ULT_T_T_T_Board<char>* s)
{
    cout << "   1   2   3" << endl;  
    for (int row = 0; row < 3; ++row)
    {
        cout << row + 1 << "  ";
        for (int col = 0; col < 3; ++col)
        {
            cout << (s->board[row][col] == '#' ? '#' : s->board[row][col]);
            if (col < 2) cout << " | ";  
        }
        cout << endl;
        if (row < 2) cout << "  -----------" << endl;
    }
    cout << endl;
}

template <typename T>
void ULT_T_T_T_Board<T>::display_board() 
{
cout << "     ";
    for (int i = 0; i < this->columns; i++) 
    {
        cout << "  " << (i + 1) << "   ";
    }
    cout << endl;

    cout << "   ╔";
    for (int i = 0; i < this->columns; i++) 
    {
        cout << "══════";
        if (i != this->columns - 1)
            cout << "╦";
    }
    cout << "╗" << endl;

    for (int i = 0; i < this->rows; i++) 
    {
        cout << " " << (i + 1) << " ║"; 
        for (int j = 0; j < this->columns; j++) 
        {
            cout << "  " << this->board[i][j] << "   ║";
        }
        cout << endl;

        if (i != this->rows - 1) 
        {
            cout << "   ╠";
            for (int j = 0; j < this->columns; j++) 
            {
                cout << "══════";
                if (j != this->columns - 1)
                    cout << "╬";
            }
            cout << "╣" << endl;
        }
    }

    cout << "   ╚";
    for (int i = 0; i < this->columns; i++) 
    {
        cout << "══════";
        if (i != this->columns - 1)
            cout << "╩";
    }
    cout << "╝" << endl;
}

template <typename T>
bool ULT_T_T_T_Board<T>::is_win()
{
    for (int i = 0; i < this->rows; i++) 
    {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != '#') ||
        (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i]  && this->board[0][i] != '#')) 
        {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != '#') ||
    (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != '#')) 
    {
        return true;
    }

    return false;
}

template <typename T>
bool ULT_T_T_T_Board<T>::is_draw() 
{
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool ULT_T_T_T_Board<T>::game_is_over()
{
    return (is_win() || is_draw());
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

template <typename T>
class ULT_T_T_T_Player : public Player<T>
{
    public:
    ULT_T_T_T_Player(string name , T symbol);
    void getmove(int &x , int &y);
};

template <typename T>
ULT_T_T_T_Player<T>::ULT_T_T_T_Player(string name , T symbol) : Player<T>(name , symbol) {}

template <typename T>
void ULT_T_T_T_Player<T>::getmove(int &x , int &y)
{
    Skip = {false , {-1 , -1}};
    cout << "Please enter (x) , (y) numbers (between 1___3) -> ex: 1 2\n";
    cin >> x >> y;
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

template <typename T>
class ULT_T_T_T_Random_Player : public RandomPlayer<T>
{
    public:
    ULT_T_T_T_Random_Player(T symbol , Board<char>* b);
    void getmove(int &x , int &y);
};

template <typename T>
ULT_T_T_T_Random_Player<T>::ULT_T_T_T_Random_Player(T symbol ,Board <char>* b) : RandomPlayer<T>(symbol) 
{
    this->boardPtr = b;
    this->dimension = 3;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void ULT_T_T_T_Random_Player<T>::getmove(int &x, int &y) 
{
    ULT_T_T_T_Board<char>* test = dynamic_cast<ULT_T_T_T_Board<char>*>(this->boardPtr);
    // if (test->game_is_over()) 
    // {
    //     Skip = {true, {-1, -1}};
    //     return;
    // }

    int index;
    do 
    {
        x = rand() % 3 + 1;  
        y = rand() % 3 + 1; 
        index = (x - 1) * 3 + (y - 1);

        // if (test->small_boards[index] == nullptr) {
        //     test->small_boards[index] = new ULT_T_T_T_Board<char>();
        // }
    } while (!test->valid_Board(x, y, test) || test->small_boards[index]->is_draw() || test->small_boards[index]->is_win());

    pair<int, int> small_move;
    do 
    {
        small_move.first = rand() % 3 + 1;  
        small_move.second = rand() % 3 + 1; 
    } while (!test->valid_Board(small_move.first, small_move.second, test->small_boards[index]));

    Skip = {true, {small_move.first, small_move.second}};
}




class Run_UI_Ultimate_Tic_tac_two
{
    public:
    void Run_UT_T_T_T();
};


void Run_UI_Ultimate_Tic_tac_two::Run_UT_T_T_T()
{
    int choice;
    Player<char>* players[2];
    Board<char>* B = new ULT_T_T_T_Board<char>();
    auto test = dynamic_cast<ULT_T_T_T_Board<char>*>(B);
    if (!test) 
    {
        cerr << "Error: Failed to cast board to ULT_T_T_T_Board." << endl;
        return;
    }
    test->set_small_board();
    string playerXName, player2Name;

    cout << "Welcome to FCAI X-O Game. :)\n";

    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) 
    {
        case 1:
            players[0] = new ULT_T_T_T_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new ULT_T_T_T_Random_Player<char>('X' , B);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) 
    {
        case 1:
            players[1] = new ULT_T_T_T_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new ULT_T_T_T_Random_Player<char>('O' , B);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return;
    }
    ULT_T_T_T_Board<char>::set_ptr(players);
    ULT_T_T_T_Board<char>::symbols = {players[0]->getsymbol() , players[1]->getsymbol()};
    GameManager<char> ULT (B, players);
    ULT.run();


    delete B;
    for (int i = 0; i < 2; ++i) 
    {
        delete players[i];
    }
}


#endif