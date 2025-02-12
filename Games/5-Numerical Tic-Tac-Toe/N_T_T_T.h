#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
using namespace std;

#ifndef N_T_T_T_H
#define N_T_T_T_H

#pragma once

class Run_UI_N_T_T_T
{
    public:
    void Run();
};


template <typename T>
class N_T_Board : public Board<T>
{
    public:
    N_T_Board();
    bool update_board (int x , int y, T symbol);
    void display_board ();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    pair <int , int> valid_input(string x , string y);
    bool valid_Board(int x , int y);
};


// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

template <typename T>
class N_T_Player : public Player<T>
{
    public:
    N_T_Player(string name , T symbol);
    void getmove(int &x , int &y);
};

template <typename T>
class N_T_Random_Player : public RandomPlayer<T>
{
    public:
    N_T_Random_Player(T symbol , Board<char>* b);
    void getmove(int &x , int &y);
};



#endif