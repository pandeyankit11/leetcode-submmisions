class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    int solve(int row, int col, vector<vector<int>>& grid, int n, int m,vector<vector<int>>&dp) {
        if (row < 0 || row >= n || col < 0 || col >= m)
            return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];
        long long ways=1;
         for(int k=0;k<4;k++){
            int nr=row+dir[k][0];
            int nc=col+dir[k][1];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>grid[row][col]){
                ways=(ways+solve(nr,nc,grid,n,m,dp))%mod;
            }
         }   

         return dp[row][col]=ways;
    }
    int countPaths(vector<vector<int>>& grid) {
        long long ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans =(ans+ solve(i, j, grid, n, m,dp))%mod;
            }
        }

        return ans;
    }
};
