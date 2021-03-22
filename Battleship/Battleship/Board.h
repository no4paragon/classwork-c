#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;

class Board
{
public:

    std::string board[10][10];
    std::string boardOpp[10][10];

    void tutorial();

    void setShips();
    void setShipsOpp();

    void attachShips();
    bool attachShipsOpp();

    void printShipsOpp(bool);
    void printShips(bool);   
};

#endif