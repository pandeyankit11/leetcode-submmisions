class Solution {
public:
   int solve(int i,int buy,vector<int> &arr,vector<vector<int>>&dp,int fee){
        if(i ==arr.size())
        return 0;
       
       if(dp[i][buy]!=-1) return dp[i][buy];
       
       int profit=0;
        if(buy){
        profit=max(-arr[i]+solve(i+1,0,arr,dp,fee),0+solve(i+1,1,arr,dp,fee));
        }
        else{
            profit=max(arr[i]-fee+solve(i+1,1,arr,dp,fee),0+solve(i+1,0,arr,dp,fee));
        }

        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp,fee);
    }
};
