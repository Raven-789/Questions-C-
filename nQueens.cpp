#include <iostream>
#include <vector>
using namespace std;

// Function to print the board configuration
void printBoard(vector<string>& board) {
    for (string row : board) {
        cout << row << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, vector<string>& board, int n) {
    // Check vertically upwards
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

// Backtracking function
void solve(int row, vector<string>& board, int n) {
    if (row == n) {
        // All queens placed
        printBoard(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';       // Place queen
            solve(row + 1, board, n);    // Move to next row
            board[row][col] = '.';       // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));  // Initialize N×N board with '.'

    cout << "\nSolutions:\n\n";
    solve(0, board, n);

    return 0;
}
