class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {

        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
            return false;
            row--;
            col--;
        }
        
        row=duprow;
        col=dupcol;

        while(col>=0){
            if(board[row][col]=='Q')
            return false;
            col--;
        }

        row=duprow;
        col=dupcol;

        while(row<n && col>=0){
            if(board[row][col]=='Q')
            return false;
            row++;
            col--;
        }
        
        return true;
    }

    void solve(int col, int n, vector<string>board,vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';

                solve(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');

        vector<string> board(n);

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<vector<string>> ans;

        solve(0, n, board, ans);
        return ans;
    }
};
