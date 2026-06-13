class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &matrix,int n,vector<vector<int>>&dp){

        if(col<0 || col>=n)
        return 1e9;

        if(row==n-1)
        return matrix[row][col];
        
        if(dp[row][col]!=-1e9) return dp[row][col];
        
       int left=matrix[row][col]+solve(row+1,col-1,matrix,n,dp);
       int right=matrix[row][col]+solve(row+1,col,matrix,n,dp);
       int mid=matrix[row][col]+solve(row+1,col+1,matrix,n,dp);

       return dp[row][col]=min({left,right,mid});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=1e9;
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        for(int i=0;i<n;i++){
           ans=min(ans,solve(0,i,matrix,n,dp));
        }

        return ans;
    }
};
