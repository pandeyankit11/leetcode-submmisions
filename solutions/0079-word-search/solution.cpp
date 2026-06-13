class Solution {
public:
    vector<vector<int>>dir={
        {1,0},
        {0,-1},
        {0,1},
        {-1,0}
    };

    bool solve(int i, int row, int col, vector<vector<char>>& board,
               string& word) {

        if (i == word.size())
            return true;

        if (row < 0 || col >= board[0].size() || col < 0 || row >= board.size()||board[row][col] == '$'||board[row][col] != word[i])
            return false;
        
        char temp=board[row][col];
        board[row][col]='$';

        for(int k=0;k<4;k++){
            if(solve(i+1,row+dir[k][0],col+dir[k][1],board,word)){
                board[row][col]=temp;
                return true;
            }
        }

        board[row][col]=temp;

        return false;
       

       

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (solve(0, i, j, board, word))
                    return true;
            }
        }
        return false;
    }
};
