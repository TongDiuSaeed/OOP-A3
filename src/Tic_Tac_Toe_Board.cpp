// Purpose: 5x5 Tic Tac Toe Game Board
// Author:  Tong Majok Kuc Akoon
// Section: S25,26
// Date:    14/12/2023

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
Tic_Tac_Toe_Board::Tic_Tac_Toe_Board() {
   n_rows = n_cols = 5;
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
bool Tic_Tac_Toe_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void Tic_Tac_Toe_Board::display_board() {
   cout << "\n-----------------------------------------------";
   for (int i: {0,1,2,3,4}) {
      cout << "\n|  ";
      for (int j: {0,1,2,3,4}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j];
         if (j == 4){
            cout<<" |";
         } else {
            cout << " | ";
         }
      }
      cout << "\n-----------------------------------------------";
   }
   cout << endl;
}

// Returns symbol if there is any winner
// either X or O
// Written in a complex way.
char Tic_Tac_Toe_Board::winner() {
   // check horizontally and diagonally
   char player_1 = 'X', player_2 = 'O';
   int a = 0, b = 0;
   for (int i = 0; i < 5; i++){
      for (int j = 0; j < 3; j++){
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
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
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

   if (a > b && n_moves == 24){
      return player_1;
   } else if (b > a && n_moves == 24){
      return player_2;
   }
   return 'd';
}

// Return true if 24 moves are done and both got the same scores.
bool Tic_Tac_Toe_Board::is_draw() {
    return (n_moves == 24 && winner() == 'd');
}

// Return true if 24 moves are done and no winner
bool Tic_Tac_Toe_Board::game_is_over () {
    return n_moves >= 24;
}
