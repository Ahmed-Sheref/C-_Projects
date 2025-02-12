#include <bits/stdc++.h>
#include "connect4.h"
using namespace std;

template <typename T>
Connect4<T>::Connect4()
{
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[this->rows];
    for (int i = 0; i <= this->rows; i++)
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j <= this->columns; j++)
        {
            this->board[i][j] = '#';
        }
    }
    this->n_moves = 0;
}

template <typename T>
int Connect4<T>::valid_input(string column)
{
    string Check_input = column;

    while (true)
    {
        if (!all_of(column.begin(), column.end(), ::isdigit)) 
        {
            cout << "Please enter a valid number (1-7)\n";
            cin >> column;
            continue;
        }
    
        int valid_number = stoi(column);
        if (valid_number >= 1 && valid_number <= 7) 
        {
            return valid_number;
        } 
        else 
        {
            cout << "Please enter a valid number between 1 and 7\n";
            cin >> column;
        }
    }
}

template <typename T>
bool Connect4<T>::update_board(int x, int y, T symbol)
{
    // x = valid_input(to_string(x));
    y = valid_input(to_string(y));

    int column = y - 1;

    while (true)
    {
        if (column < 0 || column > 7) 
        {
            cout << "!! Out Of Range\nPls enter a valid number: ";
            cin >> column; 
            column = valid_input(to_string(column));
        }

        else
            break;
    }

    int row_to_place = -1;
    for (int i = this->rows - 1; i >= 0; i--)
    {
        if (this->board[i][column] == '#') 
        {
            row_to_place = i;
            break;
        }
    }

    if (row_to_place == -1)
    {
        cout << "Column is full! Choose another column.\n";
        return false;
    }

    this->board[row_to_place][column] = symbol;
    // cout << "Player " << symbol << " placed at row " << row_to_place + 1 << " and column " << column + 1 << "\n";
    return true;
}

template <typename T>
void Connect4<T>::display_board()
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        cout << "| " << this->board[i][j] << " |";
        cout << "\n";
    }
    cout << "\n--------\n";
}

template <typename T>
bool Connect4<T>::is_win(T symbol)
{
    for (int i = 0; i < 7; ++i)
    {
        int result = 0;  // Reset for each column
        for (int j = 0; j < 6; ++j)
        {
            if (this->board[j][i] == symbol)  // Player's piece found
            {
                result++;
                if (result == 4)  // If 4 consecutive pieces are found
                {
                    return true;
                }
            }
            else
                result = 0;  // Reset if sequence is interrupted
        }
    }

    // Check for horizontal (row) winner
    for (int i = 0; i < 6; ++i)
    {
        int result = 0;  // Reset for each row
        for (int j = 0; j < 7; ++j)
        {
            if (this->board[i][j] == symbol)  // Player's piece found
            {
                result++;
                if (result == 4)  // If 4 consecutive pieces are found
                {
                    return true;
                }
            }
            else
                result = 0;  // Reset if sequence is interrupted
        }
    }

    // Check for diagonal-right (top-left to bottom-right) winner
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            int result = 0;
            // Check if we have enough space for a diagonal right (down and right)
            for (int k = 0; k < 4; ++k)
            {
                if (i + k < 6 && j + k < 7 && this->board[i + k][j + k] == symbol)
                {
                    result++;
                    if (result == 4)  // If 4 consecutive pieces are found
                    {
                        return true;
                    }
                }
                else
                    break;  // Stop checking if the diagonal is interrupted
            }
        }
    }

    // Check for diagonal-left (top-right to bottom-left) winner
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            int result = 0;
            // Check if we have enough space for a diagonal left (down and left)
            for (int k = 0; k < 4; ++k)
            {
                if (i + k < 6 && j - k >= 0 && this->board[i + k][j - k] == symbol)
                {
                    result++;
                    if (result == 4)  // If 4 consecutive pieces are found
                    {
                        return true;
                    }
                }
                else
                    break;  // Stop checking if the diagonal is interrupted
            }
        }
    }

    return false;  // No winner found
}

template <typename T>
bool Connect4<T>::is_draw()
{
    int result;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (this->board[i][j] != '#')
                result += 1; 
            if (result == 42)
            {
                cout << "*** Draw ***\n";
                return true;
            }
        }
    }
    return false;
}

template <typename T>
bool Connect4<T>::game_is_over()
{
    T symbol;
    return (is_win(symbol) || is_draw());
}

template <typename T>
Player_Connect4<T>::Player_Connect4(string name , T symbol) : Player<T>(name , symbol){}

template <typename T>
void Player_Connect4<T>::getmove(int &x, int &y)
{
    cout << "\nPlease enter your column (0 to 7): ";
    cin >> y;
}

template <typename T>
Random_Player_Connect4<T>::Random_Player_Connect4(T symbol , Board<char>* b) : RandomPlayer<T>(symbol)
{
    this->boardPtr = b;
    this->dimension = 6;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Random_Player_Connect4<T>::getmove(int& x, int& y)
{
    bool valid_move = false;
    
    Connect4<char>* connect4Board = dynamic_cast<Connect4<char>*>(this->boardPtr);

    while (!valid_move) 
    {
        // Randomly select a column (0 to 6)
        y = rand() % 7;

        for (int i = 5; i >= 0; --i) {
            if (connect4Board->getCell(i, y) == '#' and y != 0) 
            {
                x = i;  
                valid_move = true;
                break;
            }
        }
    }
}

