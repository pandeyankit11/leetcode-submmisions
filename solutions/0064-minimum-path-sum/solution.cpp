class Solution {
public:

    int solve(int row,int col,
          vector<vector<int>>& grid,
          int n,int m,vector<vector<int>>&dp){

    if(row==n-1 && col==m-1)
        return grid[row][col];

    if(row>=n || col>=m)
        return 1e9;

    if(dp[row][col]!=-1) return dp[row][col];   
    
    int right = grid[row][col] +solve(row,col+1,grid,n,m,dp);
    int down  = grid[row][col] +solve(row+1,col,grid,n,m,dp);

    return dp[row][col]=min(right,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0,0,grid,n,m,dp);
    }
};
