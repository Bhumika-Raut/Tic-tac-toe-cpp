#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic Tac Toe board
void Board(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool BoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There is an empty cell
            }
        }
    }
    return true; // All cells are filled
}

// Function to make a move
void makeMove(vector<vector<char>>& board, int row, int col, char player) {
    // Check if the cell is empty before making the move
    if (board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        cout << "Invalid move. Cell already occupied. Try again." << endl;
    }
}

int main() {
    // Initialize the Tic Tac Toe board
    vector<vector<char>> board(3, vector<char>(3, ' '));

    // Variables to keep track of the current player
    char currentPlayer = 'X';

    // Main game loop
    while (true) {
        // Display the current state of the board
        Board(board);

        // Get the player's move (row and column)
        int row, col;
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;

        // Adjust row and col to match array indexing (0-based)
        row--;
        col--;

        // Make the move
        makeMove(board, row, col, currentPlayer);

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            Board(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break; // Exit the game loop
        }

        // Check if the board is full (a tie)
        if (BoardFull(board)) {
            Board(board);
            cout << "It's a tie!" << endl;
            break; // Exit the game loop
        }

        // Switch to the other player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
