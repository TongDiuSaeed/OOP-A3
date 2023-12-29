// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include <map>
#include <iterator>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            char score = boardPtr->winner();
            if (score == 'X'){
                if (toupper(players[0]->get_symbol()) == score){
                    cout << players[0]->to_string() << " wins\n";
                    return;
                } else if (toupper(players[1]->get_symbol()) == score){
                    cout << players[1]->to_string() << " wins\n";
                    return;
                }
            } else if (score == 'O'){
                if (toupper(players[0]->get_symbol()) == score){
                    cout << players[0]->to_string() << " wins\n";
                    return;
                } else if (toupper(players[1]->get_symbol()) == score){
                    cout << players[1]->to_string() << " wins\n";
                    return;
                }
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}
