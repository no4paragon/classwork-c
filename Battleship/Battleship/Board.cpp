#include "Board.h"
#include "Ship.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>


using namespace std;

void Board::tutorial() {

    std::cout << R"(
****************************************************************************************
*   ____        _   _   _            _     _                         _           _     *
*  |  _ \      | | | | | |          | |   (_)                       (_)         | |    *
*  | |_) | __ _| |_| |_| | ___   ___| |__  _ _ __    _ __  _ __ ___  _  ___  ___| |_   *
*  |  _ < / _` | __| __| |/ _ \ / __| '_ \| | '_ \  | '_ \| '__/ _ \| |/ _ \/ __| __|  *
*  | |_) | (_| | |_| |_| |  __/ \__ \ | | | | |_) | | |_) | | | (_) | |  __/ (__| |_   *
*  |____/ \__,_|\__|\__|_|\___| |___/_| |_|_| .__/  | .__/|_|  \___/| |\___|\___|\__|  *
*                                           | |     | |            _/ |                *
*                                           |_|     |_|           |__/                 *
*                                                                                      *
****************************************************************************************
)";

    string hello = "\nThis is a marine adventure battle game where you become the captain of a pirate group and make a great voyage in search of legendary treasures!\nDefeat the pirates and get the treasures of the unknown sea!\n\n";
    int x = 0;

    while (hello[x] != '\0')
    {
        cout << hello[x];
        if (hello[x] != ' ' && hello[x] != '\n')
        Sleep(70);
        x++;
    };

}

void Board::setShipsOpp() {

    Ship Frigate("F", 2);
    Ship Sub("S", 3);
    Ship Destroyer("D", 3);
    Ship Batteleship("B", 4);
    Ship AircraftCarrier("A", 5);
    Ship arr[5] = { Frigate, Sub, Destroyer, Batteleship, AircraftCarrier };
    srand(time(NULL));
    bool occupied = false;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            boardOpp[i][j] = "[ ]";
        }
    }

    for (int i = 0; i < arr[i].size; i++) {
        occupied = true;
        while (occupied) {
            occupied = false;
            int HorV = rand() % 2;
            if (HorV == 0) {
                // Vertical
                int r = rand() % (10 - arr[i].size + 1);
                int c = rand() % 10;

                for (int j = 0; j < arr[i].size; ++j) {
                    if (boardOpp[r + j][c] != "[ ]")
                        occupied = true;
                }
                if (!occupied) {
                    for (int j = 0; j < arr[i].size; ++j) {
                        boardOpp[r + j][c] = "[" + arr[i].initial + ']';
                    }
                }
            }
            else {
                // Horizontal
                int r = rand() % 10;
                int c = rand() % (10 - arr[i].size + 1);

                for (int j = 0; j < arr[i].size; ++j) {
                    if (boardOpp[r][c + j] != "[ ]") // not empty!
                        occupied = true;
                }
                if (!occupied) {
                    for (int j = 0; j < arr[i].size; ++j) {
                        boardOpp[r][c + j] = "[" + arr[i].initial + ']';
                    }
                }
            }
        }
    }
    cout << "\nThe opponent's board" << endl;
    printShipsOpp(false);
}

void Board::setShips() {

    Ship Frigate("F", 2);
    Ship Sub("S", 3);
    Ship Destroyer("D", 3);
    Ship Batteleship("B", 4);
    Ship AircraftCarrier("A", 5);
    Ship arr[5] = { Frigate, Sub, Destroyer, Batteleship, AircraftCarrier };
    int num;
    bool occupied = false;


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = "[ ]";
        }
    }

    for (int i = 0; i < arr[i].size; i++) {
        occupied = true;
        while (occupied) {
            occupied = false;
            int HorV = rand() % 2;
            if (HorV == 0) {
                // Vertical
                int r = rand() % (10 - arr[i].size + 1);
                int c = rand() % 10;

                for (int j = 0; j < arr[i].size; ++j) {
                    if (board[r + j][c] != "[ ]") // not empty!
                        occupied = true;
                }
                if (!occupied) {
                    for (int j = 0; j < arr[i].size; ++j) {
                        board[r + j][c] = "[" + arr[i].initial + ']';
                    }
                }
            }
            else {
                // Horizontal
                int r = rand() % 10;
                int c = rand() % (10 - arr[i].size + 1);

                for (int j = 0; j < arr[i].size; ++j) {
                    if (board[r][c + j] != "[ ]") // not empty!
                        occupied = true;
                }
                if (!occupied) {
                    for (int j = 0; j < arr[i].size; ++j) {
                        board[r][c + j] = "[" + arr[i].initial + ']';
                    }
                }
            }
        }
    }
    cout << "\nThis is your board" << endl;
    printShips(true);
}

void Board::printShips(bool showShips) {

    for (char i = 'A'; i <= 'J'; i++) {
        if (i == 'A') {
            cout << "    " << i;
        }
        else {
            cout << "   " << i;
        }
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        if (i + 1 < 10) {
            cout << i + 1 << "  ";
        }
        else {
            cout << i + 1 << " ";
        }
        for (int j = 0; j < 10; j++) {
            if (showShips) {
                cout << board[i][j] << " ";
            }
            else {
                if (board[i][j] != "[x]" && board[i][j] != "[o]") {
                    cout << "[ ] ";
                }
                else {
                    cout << board[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
}

void Board::printShipsOpp(bool showShips) {

    for (char i = 'A'; i <= 'J'; i++) {
        if (i == 'A') {
            cout << "    " << i;
        }
        else {
            cout << "   " << i;
        }
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        if (i + 1 < 10) {
            cout << i + 1 << "  ";
        }
        else {
            cout << i + 1 << " ";
        }
        for (int j = 0; j < 10; j++) {
            if (showShips) {
                cout << boardOpp[i][j] << " ";
            }
            else {
                if (boardOpp[i][j] != "[x]" && boardOpp[i][j] != "[o]") {
                    cout << "[ ] ";
                }
                else {
                    cout << boardOpp[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
}

void Board::attachShips() {
    int r, c;
    int missed = 15;
    int hit = 0;
    char cl;
    string attack, quit;
    bool attacked = true;

    while (attacked) {

        cout << "\nEnter the position you are attacking (Letters for column, numbers for row): " << endl;
        cout << "O for a miss or a X for a hit. Type 999 to quit." << endl;
        cin >> quit;

        if (quit != "999") {
            cl = quit[0];
            c = cl - 'A' + 1;
            r = stoi(quit.substr(1),nullptr);
            
            attacked = false;

            if (boardOpp[r - 1][c - 1] == "[o]" || boardOpp[r - 1][c - 1] == "[x]") {
                cout << "\nYour are attacking the same spot. Try again";
                attacked = true;
            }
            else {
                if (boardOpp[r - 1][c - 1] == "[ ]") {
                    boardOpp[r - 1][c - 1] = "[o]";
                    missed--;
                    cout << "\nMissed!! You can miss " << missed << " more times" << endl << endl;
                    if (missed == 0) {
                        cout << "The opponent's board" << endl;
                        printShipsOpp(false);
                        cout << "==========================================" << endl;
                        cout << "Your board" << endl;
                        printShips(true);
                        cout << "\nGAME OVER";
                        cout << "\nYou missed too many times..." << endl;
                        return;
                    }
                }
                else {
                    boardOpp[r - 1][c - 1] = "[x]";
                    missed = 15;
                    hit++;
                    if (hit == 17) {
                        cout << "The opponent's board" << endl;
                        printShipsOpp(false);
                        cout << "==========================================" << endl;
                        cout << "Your board" << endl;
                        printShips(true);
                        cout << "\nYOU WON!!";
                        cout << "\nYou attacked all the ships!!";
                        return;
                    }
                }
                attacked = attachShipsOpp(); 
            }
            cout << "The opponent's board" << endl;
            printShipsOpp(false);
            cout << "==========================================" << endl;
            cout << "Your board" << endl;
            printShips(true);
        }
        else {
            attacked = false;
        }
    }
}

bool Board::attachShipsOpp() {
    int r, c;
    static int missed = 15;
    static int hit = 0;
    bool attacked = true;

    r = rand() % (10) + 1;
    c = rand() % (10) + 1;

    while (attacked) {

        attacked = false;

        if (board[r - 1][c - 1] == "[o]" || board[r - 1][c - 1] == "[x]") {
            attacked = false;
            attachShipsOpp();
        }
        else {
            if (board[r - 1][c - 1] == "[ ]") {
                board[r - 1][c - 1] = "[o]";
                missed--;
                if (missed == 0) {
 
                    cout << "The opponent's board" << endl;
                    printShipsOpp(false);
                    cout << "==========================================" << endl;
                    cout << "Your board" << endl;
                    cout << "\nYOU WON!!";
                    cout << "\nOpponent missed too many times..." << endl;
                    printShips(true);

                    return false;
                }
            }
            else {
                board[r - 1][c - 1] = "[x]";
                missed = 15;
                hit++;
                if (hit == 17) {
                    cout << "The opponent's board" << endl;
                    printShipsOpp(false);
                    cout << "==========================================" << endl;
                    cout << "Your board" << endl;
                    cout << "\nYOU LOSE!!";
                    cout << "\nThe opponent attacked all of your ships" << endl;
                    printShips(true);
                    return false;
                }
            }
        }
    }
    return true;
}




