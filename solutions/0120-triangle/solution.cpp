class Solution {
public:

    int solve(int row,int col,vector<vector<int>>&triangle,int n,int m,vector<vector<int>>&dp){
        if(row==n-1){
            return triangle[row][col];
        }
        

        if(dp[row][col]!=-1e9) return dp[row][col];
       
        int left=triangle[row][col]+solve(row+1,col,triangle,n,m,dp);
        int right=triangle[row][col]+solve(row+1,col+1,triangle,n,m,dp);


        return dp[row][col]=min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
       vector<vector<int>>dp(n,vector<int>(m,-1e9));
       return solve(0,0,triangle,n,m,dp);
    }
};
