class Solution {
public:
      int solve(int i,int buy,int cap,vector<int> &arr,vector<vector<vector<int>>>&dp){
        if(cap==0 || i ==arr.size())
        return 0;
       
       if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
       
       int profit=0;
        if(buy){
        profit=max(-arr[i]+solve(i+1,0,cap,arr,dp),0+solve(i+1,1,cap,arr,dp));
        }
        else{
            profit=max(arr[i]+solve(i+1,1,cap-1,arr,dp),0+solve(i+1,0,cap,arr,dp));
        }

        return dp[i][buy][cap]=profit;
      }

    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};
