class Solution {
public:
    vector<bool> column; // To store occupancy of columns

    vector<bool> TL_to_BR_diagonal; // To store occupancy of diagonal
                                    // (TL to BR)

    vector<bool> TR_to_BL_diagonal; // To store occupancy of diagonal
                                    // (TR to BL)

    vector<vector<string>> ans; // To store answer board states

    bool isValid(int row, int col, int n) {
        int c = col;
        int d1 = row - col + (n - 1);
        int d2 = row + col;
        ;

        if (column[c] == true || TL_to_BR_diagonal[d1] == true ||
            TR_to_BL_diagonal[d2] == true) {
            return (false); // Attacking queen
        }
        return (true); // No queen attacking
    }

    void backtrack(int n, vector<string>& board, int row) {
        // Base Case(saving solution)
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Trying all possible positions of queen in current row
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, n)) {
                board[row][i] = 'Q'; // Place queen on board

                column[i] = true; // Indicate column occupancy
                TL_to_BR_diagonal[(row - i) + (n - 1)] =
                    true; // Indicate diagonal occupancy
                          // (TL to BR)
                TR_to_BL_diagonal[row + i] = true; // Indicate diagonal
                                                   // occupancy (TR to BL)

                backtrack(n, board, row + 1); // Proceed to next row

                board[row][i] = '.'; // Undo queen placement

                column[i] = false; // Undo column occupancy
                TL_to_BR_diagonal[(row - i) + (n - 1)] =
                    false;                          // Undo diagonal occupancy
                TR_to_BL_diagonal[row + i] = false; // Undo diagonal occupancy
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');           // Empty row on board
        vector<string> board(n, s); // Empty board

        // Initializing occupancy vectors
        column = vector<bool>(n, false);
        TL_to_BR_diagonal = vector<bool>(2 * n - 1, false);
        TR_to_BL_diagonal = vector<bool>(2 * n - 1, false);

        backtrack(n, board, 0); // Begin with row '0'

        return (ans); // Return all possible board states
    }
};