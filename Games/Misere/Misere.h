#ifndef _Misere
#define _Misere
#include "BoardGame_Classes.h"

bool is_computer_word = false;

template <typename T>
class Misere_Board : public Board<T>{
    public:
        Misere_Board();
        bool update_board(int x, int y, T mark);
        void display_board();
        bool is_win();
        bool is_draw();
        bool game_is_over();
        void swap_players();
};

template <typename T>
class Misere_Player : public Player<T>{
    public:
        void setname(const string& new_name); 
        static void swap_names(Misere_Player<T>* p1, Misere_Player<T>* p2); 
        static Player<T>** Ptr;
        static void Set_ptr(Player<T>** P);
        Misere_Player(string name , T sy);
        void getmove(int& x, int& y);
};

template <typename T>
class Misere_RandomPlayer : public RandomPlayer<T>{
    public:
       Misere_RandomPlayer(T sy);
        void getmove(int& x, int& y);

};

class UI_Misere{
    public:
        void Main_Program();  
};



#endif