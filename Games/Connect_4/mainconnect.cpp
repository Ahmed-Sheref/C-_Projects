#include <bits/stdc++.h>
#include "connect4.cpp"
using namespace std;


int main()
{
    int choice;
    Player<char>* players[2];
    Board<char>* B = new Connect4<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI Connect_4 Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) 
    {
        case 1:
            players[0] = new Player_Connect4<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new Random_Player_Connect4<char>('X' , B);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
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
            players[1] = new Player_Connect4<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new Random_Player_Connect4<char>('O' , B);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }

    // Create the game manager and run the game
    GameManager<char> conn_4 (B, players);
    conn_4.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) 
    {
        delete players[i];
    }

    return 0;
}