#ifndef _Sus_1
#define _Sus_1

#include "BoardGame_Classes.h"
#include <iostream>
using namespace std;

int player_1_wins = 0;
int player_2_wins = 0;
string player_1_nm;
string player_2_nm;
string last_player;
int counter = -1;
bool checked_rows[3] = {false, false, false};
bool checked_cols[3] = {false, false, false};
bool checked_diagonals[2] = {false, false};
bool no_more_SUS_possible = false;
bool is_computer = false;
Player<char>** players_ptr;


template <typename T>
class Sus_Board : public Board<T>{
   

    public:
        Sus_Board();
        bool update_board(int x, int y, T mark);
        void display_board();
        bool is_win();
        bool is_draw();
        bool game_is_over();
        void Get_Sus(int& p1_wins , int& p2_wins , int counter);
        char getCell(int x, int y);
        bool check_Word(char first_letter , char second_letter , char third_letter);
        bool can_complete_sus(char c1 , char c2 , char c3);

};

template <typename T>
class Sus_Player : public Player<T>{
    public:
        static Player<T>** Ptr;
        static void Set_ptr(Player<T>** P);
        Sus_Player(string name , T sy);
        void getmove(int& x, int& y);
};

template <typename T>
class Sus_RandomPlayer : public RandomPlayer<T>{
    public:
        Sus_RandomPlayer(T sy);
        void getmove(int& x, int& y);

};

class UI_Sus{
    public:
        void Main_Program();  
};

#endif