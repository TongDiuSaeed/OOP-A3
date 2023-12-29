// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
X_O_Board::X_O_Board () {
   n_rows = n_cols = 3;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
   for (int i: {0,1,2}) {
      cout << "\n| ";
      for (int j: {0,1,2}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n--------------------------";
   }
   cout << endl;
}

// Returns symbol if there is any winner
// either X or O
// Written in a complex way.
char X_O_Board::winner() {
   // check horizontally and diagonally
   char player_1 = 'X', player_2 = 'O';
   int a = 0, b = 0;
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 1; j ++){
         // check horizontally
         if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j] == player_1){
            a++;
         } else if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j] == player_2){
            b++;
         }
         // check vertically
         if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j][i] == player_1){
            a++;
         } else if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j][i] == player_2){
            b++;
         }
      }
   }
   // check diagonally
   for (int i = 0; i < 1; i++){
      for (int j = 0; j < 1; j++){
         // check diagonally (top-left to bottom-right)
         if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i][j] == player_1){
            a++;
         } else if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i][j] == player_2){
            b++;
         }
         // check diagonally (top-right to bottom-left)
         if (board[i][j+2] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j] && board[i][j+2] == player_1){
            a++;
         } else if (board[i][j+2] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j] && board[i][j+2] == player_2){
            b++;
         }
      }
   }

   if (a > 0){
      return player_1;
   } else if (b > 0){
      return player_2;
   }
   return 'd';
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && winner() == 'd');
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}
