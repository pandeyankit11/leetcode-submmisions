class Solution {
public:
    int solve(int i,vector<int>&arr,int k,vector<int>&dp){
        int n=arr.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0;
        int maxAns=INT_MIN;
        int max_ele=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
           max_ele=max(arr[j],max_ele);
           len++;
           int sum=len*max_ele +solve(j+1,arr,k,dp);
           maxAns=max(maxAns,sum);
        }

        return dp[i]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,k,dp);
    }
};
