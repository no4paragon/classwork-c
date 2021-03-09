#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

using namespace std;

class Board
{

private:

    static const int ROWS = 8;
    static const int COLS = 8;
    string arr[ROWS][COLS];
    int a;
    int move = 1;

public:
    Board(){}
    void legalMoves(int currentRow, int currentCol);
   
};

#endif