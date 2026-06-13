class Solution {
public:

    int solve(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0)
        return 1;
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        int ways=0;

        for(int j=i;j<coins.size();j++){
            if(amount-coins[j]>=0)
            ways+=solve(j,amount-coins[j],coins,dp);
        }

        return dp[i][amount]=ways;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};
