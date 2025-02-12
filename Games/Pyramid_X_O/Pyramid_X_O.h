#ifndef _Pyramid_X_O_H
#define _Pyramid_X_O_H

#include "BoardGame_Classes.h"

template <typename T>
class Pyramid_X_O_Board : public Board<T>{
    public:
        Pyramid_X_O_Board();
        bool update_board(int x, int y, T mark);
        void display_board();
        bool is_win();
        bool is_draw();
        bool game_is_over();
};

template <typename T>
class Pyramid_X_O_Player : public Player<T>{
    public:
        Pyramid_X_O_Player(string name , T sy);
        void getmove(int& x, int& y , int player_num);
};

template <typename T>
class Pyramid_X_O_RandomPlayer : public RandomPlayer<T>{
    public:
        Pyramid_X_O_RandomPlayer(T sy);
        void getmove(int& x, int& y, int player_num);
};

class UI{
    public:
        void Main_Program(){
            string choice;
            Player<char>* players[2];
            Pyramid_X_O_Board<char>* B = new Pyramid_X_O_Board<char>();
            string player1Name, player2Name;
            cout << "===============================================================\n\n";
            cout << "               Welcome to the Pyramid X-O Game!\n";
            cout << "     A fun twist on the classic Tic-Tac-Toe game in pyramid style.\n\n";
            cout << "                    Controls:\n";
            cout << "                    1. Enter the row (X)\n";
            cout << "                    2. Enter the column (Y)\n";
            cout << "                    3. Get 3 in a row to WIN!\n\n";
            cout << "         Are you ready to test your strategy and luck? 🎮\n\n";
            cout << "===============================================================\n\n";

            // Set up player 1
            cout << "Enter Player 1 name: ";
            getline(cin,player1Name);
            while (true){
                cout << "Choose Player 1 type:\n";
                cout << "1. Human\n";
                cout << "2. Random Computer\n";
                getline(cin,choice);
                
                if(choice == "1"){
                    players[0] = new Pyramid_X_O_Player<char>(player1Name, 'X');
                    break;
                }
                else if(choice == "2"){
                    players[0] = new Pyramid_X_O_RandomPlayer<char>('X');
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
            while(true){
                cout << "Choose Player 2 type:\n";
                cout << "1. Human\n";
                cout << "2. Random Computer\n";
                getline(cin,choice);

                if(choice == "1"){
                    players[1] = new Pyramid_X_O_Player<char>(player2Name, 'O');
                    break;
                }
                else if(choice == "2"){
                    players[1] = new Pyramid_X_O_RandomPlayer<char>('O');
                    break;
                }
                else{
                    cout << RED << "Invalid choice for Player 2." << RESET << endl;
                    continue;
                }
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
};











#endif