
#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
	Board create;
	int row, col;


	cout << "Your current position on the board (input first row, then column): ";
	cin >> row >> col;

	create.legalMoves(row, col);

 

	return 0;
}