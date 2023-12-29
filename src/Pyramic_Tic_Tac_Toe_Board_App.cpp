// Purpose: Pyramic Tic Tac Toe Implementation
// Author:  Atem Abuok Deng Gai
// Section: S15,16
// Date:    14/12/2023

#include <iostream>
#include "../include/BoardGame_Classes.hpp"
#include "GameManager.cpp"
#include "Player.cpp"
#include "Pyramic_Tic_Tac_Toe_Board.cpp"
#include "PyramicRandomPlayer.cpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new PyramicRandomPlayer ('o', 3, 5);

    GameManager x_o_game (new Pyramic_Tic_Tac_Toe_Board(), players);
    x_o_game.run();
    system ("pause");
}
