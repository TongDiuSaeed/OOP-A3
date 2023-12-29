// Purpose: Four-in-a-row Game Board
// Author:  Amna Mohamed Elsharabassy
// Section: S15,16
// Date:    14/12/2023

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <map>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
Four_In_A_Row_Board::Four_In_A_Row_Board() {
   n_rows = 6;
   n_cols = 7;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++){
         board[i][j] = 0;
      }
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Four_In_A_Row_Board::update_board(int x, int y, char symbol) {
    if (y < 0 || y >= n_cols || board[0][y] != 0) {
        return false;  // Column is full
    }
    int row = 0;
    while (row < n_rows - 1 && board[row + 1][y] == 0) {
        row++;
    }
    
    board[row][y] = toupper(symbol);
    n_moves++;
    return true;
}

// Display the board and the pieces on it
void Four_In_A_Row_Board::display_board() {
   cout << "\n----------------------------------------------------------------";
   for (int i: {0,1,2,3,4,5}) {
      cout << "\n|  ";
      for (int j: {0,1,2,3,4,5,6}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j];
         if (j == 4){
            cout<<" |";
         } else {
            cout << " | ";
         }
      }
      cout << "\n----------------------------------------------------------------";
   }
   cout << endl;
}

// Returns symbol if there is any winner
// either X or O
// Written in a complex way.
char Four_In_A_Row_Board::winner() {
   // check horizontally and diagonally
   char player_1 = 'X', player_2 = 'O';
   int a = 0, b = 0;
   // Check for horizontal wins
      for (int row = 0; row < n_rows; ++row) {
        for (int col = 0; col <= n_cols - 4; ++col) {
            if (board[row][col] == player_1 &&
                board[row][col] == board[row][col + 1] &&
                board[row][col] == board[row][col + 2] &&
                board[row][col] == board[row][col + 3]) {
                a++;
            } else if (board[row][col] == player_2 &&
                board[row][col] == board[row][col + 1] &&
                board[row][col] == board[row][col + 2] &&
                board[row][col] == board[row][col + 3]){
                b++;
            }
        }
    }

    // Check for vertical wins
    for (int col = 0; col < n_cols; ++col) {
        for (int row = 0; row <= n_rows - 4; ++row) {
            if (board[row][col] == player_1 &&
                board[row][col] == board[row + 1][col] &&
                board[row][col] == board[row + 2][col] &&
                board[row][col] == board[row + 3][col]) {
                a++;
            } else if (board[row][col] == player_2 &&
                board[row][col] == board[row + 1][col] &&
                board[row][col] == board[row + 2][col] &&
                board[row][col] == board[row + 3][col]) {
                b++;
            }
        }
    }

    // Check for diagonal wins (positive slope)
    for (int row = 0; row <= n_rows - 4; ++row) {
        for (int col = 0; col <= n_cols - 4; ++col) {
            if (board[row][col] == player_1 &&
                board[row][col] == board[row + 1][col + 1] &&
                board[row][col] == board[row + 2][col + 2] &&
                board[row][col] == board[row + 3][col + 3]) {
                a++;
            } else if (board[row][col] == player_2 &&
                board[row][col] == board[row + 1][col + 1] &&
                board[row][col] == board[row + 2][col + 2] &&
                board[row][col] == board[row + 3][col + 3]) {
                b++;
            }
        }
    }

    // Check for diagonal wins (negative slope)
    for (int row = 3; row < n_rows; ++row) {
        for (int col = 0; col <= n_cols - 4; ++col) {
            if (board[row][col] == player_1 &&
                board[row][col] == board[row - 1][col + 1] &&
                board[row][col] == board[row - 2][col + 2] &&
                board[row][col] == board[row - 3][col + 3]) {
                a++;
            } else if (board[row][col] == player_2 &&
                board[row][col] == board[row - 1][col + 1] &&
                board[row][col] == board[row - 2][col + 2] &&
                board[row][col] == board[row - 3][col + 3]) {
                b++;
            }
        }
    }

   if (a > 0){
      return player_1;
   } else if (b > 0){
      return player_2;
   }
//    cout<<"\nPlayer 1 ["<<player_1<<"]: "<<a<<"\nPlayer 2 ["<<player_2<<"]: "<<b<<"\n";
   return 'd';
}

// Return true if 9 moves are done and no winner
bool Four_In_A_Row_Board::is_draw() {
    return (n_moves == 42 && winner() == 'd');
}

bool Four_In_A_Row_Board::game_is_over () {
    return n_moves >= 42;
}