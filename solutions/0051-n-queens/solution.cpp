class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {

        // Check same column
        for (int r = 0; r < row; r++) {
            if (board[r][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<vector<char>>& ans,vector<vector<string>>& res) {
        if (row == n) {
            vector<string>temp;
            for (int i = 0; i < n; i++) {

                string s = "";

                for (int j = 0; j < n; j++) {
                    s.push_back(ans[i][j]);
                }

                temp.push_back(s);
            }
            res.push_back(temp);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, ans, n)) {
                ans[row][col] = 'Q';

                solve(row + 1, n, ans,res);
                ans[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> ans(n, vector<char>(n, '.'));
        vector<string> temp;
        vector<vector<string>> res;

        solve(0, n, ans, res);
        return res;
    }
};
