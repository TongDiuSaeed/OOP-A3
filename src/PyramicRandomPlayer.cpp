// Purpose: Pyramic Tic Tac Toe Game Random Computer Player
// Author:  Atem Abuok Deng Gai
// Section: S15,S16
// Date:    14/12/2023

#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
PyramicRandomPlayer::PyramicRandomPlayer (char symbol, int dimension_x, int dimension_y):Player(symbol)
{
    this->dimension_x = dimension_x;
    this->dimension_y = dimension_y;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void PyramicRandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension_x);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension_y);
}
