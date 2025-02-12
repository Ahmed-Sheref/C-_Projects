#include <bits/stdc++.h>
#include "N_T_T_T.h"
using namespace std;

map <int , int> Only_Ones_use;
pair<bool , int> Skip;



template <typename T>
N_T_Board<T>::N_T_Board()
{
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->columns; i++)
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->board[i][j] = '#';
        }
    }
    this->n_moves = 0;
}

template <typename T>
pair <int , int> N_T_Board<T>::valid_input(string x , string y)
{

    while (true)
    {
        string Check_input_X = x;
        string Check_input_y = y;
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
bool N_T_Board<T>::valid_Board(int x , int y)
{
    return !(isdigit(this->board[x][y]));
}

template <typename T>
bool N_T_Board<T>::update_board(int x , int y , T symbol)
{
    pair<int, int> valid_coords = valid_input(to_string(x), to_string(y));
    x = valid_coords.first;
    y = valid_coords.second;
    x--; y--;
    int number;
    vector <int> Odd_numbers {1,3,5,7,9};
    vector <int> Even_numbers {2,4,6,8};
    vector <int> main_vector = (symbol == 'X' ? Odd_numbers : Even_numbers);
    if (Skip.first) 
    {
        number = Skip.second;
    } 
    else 
    {
        cout << "Enter your number from your Vector -> [  ";
        copy(main_vector.begin(), main_vector.end(), ostream_iterator<int>(cout, " "));
        cout << " ] : ";
        cin >> number;
    }

    if (!valid_Board(x , y) || find(main_vector.begin() , main_vector.end() , number) == main_vector.end() || Only_Ones_use[number] >= 1)
    {
        cout << "Invalid number Or ((REPEATED))... Please again the index and Select from own number\n";
        return false;
    }
    this->board[x][y] = number + '0';
    this->n_moves++;
    Only_Ones_use[number]++;
    return true;
}

template <typename T>
void N_T_Board<T>::display_board() 
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
bool N_T_Board<T>::is_win()
{
    int sum = 0 , Objective = 15;
    int count = 0;
    // Check row
    for (int i = 0; i < this->rows; i++)
    {
        sum = 0;
        for (int j = 0; j < this->columns; j++)
        {
            if ((this->board[i][j]) != '#')
            {
                sum += this->board[i][j] - '0';
                count++;
            }
            else break;
        }
        if (sum == Objective and count == 3)
        {
            return true;
        }
    }
    // ----
    // Check columns
    sum = count = 0;
    for (int i = 0; i < this->rows; i++)
    {
        sum = 0;
        for (int j = 0; j < this->columns; j++)
        {
            if ((this->board[j][i]) != '#')
            {
                sum += this->board[i][j] - '0';
                count++;
            }
            else break;
        }
        if (sum == Objective and count == 3)
        {
            return true;
        }
    }
    // ----
    // Check Diagonal right
    sum = 0;
    if (this->board[0][0] - '0' + this->board[1][1] - '0' + this->board[2][2] - '0' == Objective)
        return true;
    // ----
    // Check Diagonal left
    sum = 0;
    if (this->board[2][0] - '0' + this->board[1][1] - '0' + this->board[0][2] - '0' == Objective)
        return true;
    return false;
}

template <typename T>
bool N_T_Board<T>::is_draw()
{
    return (this->n_moves == 9 and !is_win());
}

template <typename T>
bool N_T_Board<T>::game_is_over()
{
    return (is_win() || is_draw());
}

template <typename T>
N_T_Player<T>::N_T_Player(string name , T symbol) : Player<T>(name , symbol) {}

template <typename T>
void N_T_Player<T>::getmove(int &x , int &y)
{
    Skip = {false , -1};
    cout << "Please enter (x) , (y) numbers (between 1___3) -> ex: 1 2\n";
    cin >> x >> y;
}

template <typename T>
N_T_Random_Player<T>::N_T_Random_Player(T symbol ,Board <char>* b) : RandomPlayer<T>(symbol) 
{
    this->boardPtr = b;
    this->dimension = 3;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void N_T_Random_Player<T>::getmove(int &x , int &y)
{
    N_T_Board<char>* test = dynamic_cast<N_T_Board<char>*> (this->boardPtr); 
    
    vector<int> odd_numbers = {1, 3, 5, 7, 9};  
    vector<int> even_numbers = {2, 4, 6, 8};
    vector<int> selected_numbers = (this->symbol == 'X' ? odd_numbers : even_numbers);
    
    int number = 0;
    bool Check_random_role;
    do 
    {
        number = selected_numbers[rand() % selected_numbers.size()];

        x = rand() % (this->dimension + 1); 
        y = rand() % (this->dimension + 1); 

        if(x > 0 and y > 0)
            Check_random_role = test->valid_Board(x-1, y-1);

    } while (x <= 0 || y <= 0 || Only_Ones_use[number] >= 1 || !Check_random_role);

    Skip = {true, number};
}

void Run_UI_N_T_T_T::Run()
{
    int choice;
    Player<char>* players[2];
    Board<char>* B = new N_T_Board<char>();
    string playerXName, player2Name;
    cout << "Welcome to FCAI Numerical Tic-Tac-Toe Game. :)\n";

    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) 
    {
        case 1:
            players[0] = new N_T_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new N_T_Random_Player<char>('X' , B );
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return;
    }

    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) 
    {
        case 1:
            players[1] = new N_T_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new N_T_Random_Player<char>('O' , B);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return;
    }

    GameManager<char> N_T (B, players);
    N_T.run();

    delete B;
    for (int i = 0; i < 2; ++i) 
    {
        delete players[i];
    }
    return;
}
