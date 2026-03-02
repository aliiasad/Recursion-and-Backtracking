# include <iostream>
# include <cmath>
using namespace std;

bool isSafe (int board[], int row, int col, int n);
bool solve (int board[], int row, int n);

int main()  {
    int n =4;
    int board[4];
    for (int i = 0; i < n; i++) board[i] = -1;
    if (solve(board, 0, n)) {
        for (int i = 0; i < n; i++) {
            cout << "Row " << i << ": Queen at column " << board[i] << endl;
        }
    } else {
        cout << "No solution found" << endl;
    }
}

bool isSafe (int board[], int row, int col, int n)  {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || (abs(row - i) == abs(col - board[i]))) 
            return false;
    }
    return true;
}

bool solve (int board[], int row, int n)    {
    if (row == n) return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i, n))  {
            board[row] = i;
            if (solve (board, row + 1, n)) return true;
            board[row] = -1;
        }
    }
    return false;
}