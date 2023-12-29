// Purpose: Four-in-a-row Game's Random Computer Player
// Author:  Amna Mohamed Elsharabassy
// Section: S15,16
// Date:    14/12/2023

#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
FourRandomPlayer::FourRandomPlayer (char symbol, int dimension_x, int dimension_y):Player(symbol)
{
    this->dimension_x = dimension_x;
    this->dimension_y = dimension_y;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void FourRandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension_x);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension_y);
}
