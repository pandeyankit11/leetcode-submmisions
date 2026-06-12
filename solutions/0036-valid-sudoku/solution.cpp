class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {

            if (i != row && board[i][col] == c)
                return false;

            if (i != col && board[row][i] == c)
                return false;

            int subRow = 3 * (row / 3) + (i / 3);
            int subCol = 3 * (col / 3) + (i % 3);
            if ((subRow != row || subCol != col) && board[subRow][subCol] == c)
                return false;
        }
            return true;
        
    }

        bool solve(vector<vector<char>> & board) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] != '.') {
                        if (!isValid(board, i, j, board[i][j])) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        bool isValidSudoku(vector<vector<char>> & board) {
            return solve(board);
        }
    };
