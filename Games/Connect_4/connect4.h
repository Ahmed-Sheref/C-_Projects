#ifndef CONNECT4_H
#define CONNECT4_H

#include "BoardGame_Classes.h"

#pragma once

template <typename T>
class Connect4 : public Board<T>
{
    public:
        Connect4();
        bool update_board (int x , int y, T symbol);
        void display_board ();
        bool is_win(T symbol);
        bool is_draw();
        bool game_is_over();
        int valid_input(string column);
        char getCell (int row , int column)
        {
            return this->board[row][column];
        }
};

template <typename T>
class Player_Connect4 : public Player<T>
{
    public:
    Player_Connect4(string name , T symbol);
    void getmove (int &x , int &y);
};

template <typename T>
class Random_Player_Connect4 : public RandomPlayer<T>
{
    public:
    Random_Player_Connect4(T symbol , Board<char>* b);
    void getmove (int &x , int &y);
};

#endif