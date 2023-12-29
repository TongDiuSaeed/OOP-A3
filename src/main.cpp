// Purpose: Games menu
// Author(s):  Tong Majok Kuc Akoon, Amna Mohamed Elsharabassy, Atem Abuok Deng Gai
// Section: S15, S16, S25
// Date:    14/12/2023

#include <iostream>
#include "../include/BoardGame_Classes.hpp"
#include "GameManager.cpp"
#include "Player.cpp"
#include "X_O_Board.cpp"
#include "Tic_Tac_Toe_Board.cpp"
#include "Pyramic_Tic_Tac_Toe_Board.cpp"
#include "Four_In_A_Row_Board.cpp"
#include "PyramicRandomPlayer.cpp"
#include "RandomPlayer.cpp"
#include "FourRandomPlayer.cpp"
using namespace std;

int main() {
    while (true){
        int select;
        cout << "\nWelcome to FCAI Games Menu :)\nBelow is a list of games to play:\n";
        cout << "1. X-O Board Game\n2. Pyramic Tic Tac Toe\n3. Tic Tac Toe\n4. Four-in-a-row\n";
        cout << "\nChoice > > > ";
        cin >> select;
        if (select == 1){
            cout << "\nWelcome to X-O Game. :)\n";
            int choice;
            Player* players[2];
            players[0] = new Player (1, 'x');

            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer ('o', 3);

            GameManager x_o_game (new X_O_Board(), players);
            x_o_game.run();
            system ("pause");
            
        } else if (select == 2){
            cout << "\nWelcome to Pyramic Tic Tac Toe Game. :)\n";
            int choice;
            Player* players[2];
            players[0] = new Player (1, 'x');

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
        } else if (select == 3){
            cout << "\nWelcome to Tic Tac Toe Game. :)\n";
            int choice;
            Player* players[2];
            players[0] = new Player (1, 'x');

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
        } else if (select == 4){
            cout << "\nWelcome to Four-in-a-row Game. :)\n";
            int choice;
            Player* players[2];
            players[0] = new Player (1, 'x');
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new FourRandomPlayer ('o', 6, 7);

            GameManager x_o_game (new Four_In_A_Row_Board(), players);
            x_o_game.run();
            system ("pause");
        } else {
            cout << "\nInvalid choice!\n";
        }
    }
}
