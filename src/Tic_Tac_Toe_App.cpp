// Purpose: Tic Tac Toe Game
// Author:  Tong Majok Kuc Akoon
// Section: S25,26
// Date:    14/12/2023

#include <iostream>
#include "../include/BoardGame_Classes.hpp"
#include "GameManager.cpp"
#include "Player.cpp"
#include "Tic_Tac_Toe_Board.cpp"
#include "RandomPlayer.cpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Tic Tac Toe Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new Tic_Tac_Toe_Board(), players);
    x_o_game.run();
    system ("pause");
}
