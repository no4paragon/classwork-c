#include "Board.h"

void Board::legalMoves(int currentRow, int currentCol)
{

    struct Pos {
        int row;
        int col;
    };

    Pos moves[8];
    a = 0;

    while (a != 999) {
        move = 1;

        //Initialize array with empty spaces
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                arr[r][c] = "[ ]";
            }
        }

        cout << "Your current position on the board is [" << currentRow << "][" << currentCol << "] \n";
        arr[currentRow][currentCol] = "[X]";

        //Show the current position on the board
        cout << "  0  1  2  3  4  5  6  7\n";
        for (int r = 0; r < ROWS; r++)
        {
            cout << r;
            for (int c = 0; c < COLS; c++)
            {
                cout << arr[r][c];
            }

            cout << endl;
        }
        cout << endl;

        int row, col;

        cout << "For this position legal moves are:\n";

        // to move up
        row = currentRow - 2; col = currentCol + 1;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }

        row = currentRow - 1; col = currentCol + 2;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }

        // to move right
        row = currentRow + 1; col = currentCol + 2;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }
        row = currentRow + 2; col = currentCol + 1;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }

        // to move down
        row = currentRow + 2; col = currentCol - 1;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }
        row = currentRow + 1; col = currentCol - 2;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }

        // to move left
        row = currentRow - 1; col = currentCol - 2;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }
        row = currentRow - 2; col = currentCol - 1;
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            moves[move - 1].row = row;
            moves[move - 1].col = col;
            cout << move << "." << " board[" << row << "][" << col << "] or \n";
            arr[row][col] = "[L]";
            move++;
        }
        cout << endl;

        // Show the board with all legal moves from the current position
        // Legal moves will be indicated as 'L'
        cout << "  0  1  2  3  4  5  6  7\n";
        for (int r = 0; r < ROWS; r++)
        {
            cout << r;
            for (int c = 0; c < COLS; c++)
            {
                cout << arr[r][c];
            }
            cout << endl;
        }

        cout << "\nPLEASE SELECT YOUR NEXT MOVE" << endl;
        cout << "To MOVE, select the number" << endl;
        cout << "To START NEW GAME, type '0'" << endl;
        cout << "To END, type '999'" << endl;
        cin >> a;

        if (a == 0) {
            
            cout << "Your current position on the board (input first row, then column): ";
            cin >> currentRow >> currentCol;
        }
        else if (a == 999) {
            return;
        }
        else {
            cout << "\nYOU MADE A MOVE!!" << endl;
            currentRow = moves[a - 1].row;
            currentCol = moves[a - 1].col;
        }
    }
}