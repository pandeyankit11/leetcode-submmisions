class Solution {
public:
    int solve(int i,vector<int> &coins,int amount,vector<vector<int>>&dp){
        if(amount==0)
        return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int ans=1e9;
        for(int j=i;j<coins.size();j++){
        if(amount-coins[j]>=0)
        ans=min(ans,1+solve(j,coins,amount-coins[j],dp));
        }

        return dp[i][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= solve(0,coins,amount,dp);

        return ans>=1e9 ?-1 :ans;
    }
};
