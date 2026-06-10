class Solution {
public:

    bool solve(int i,vector<int>&nums,int currSum,int target,vector<vector<int>>&dp){
        if(i==nums.size()){
            return false;
        }
        
        if(currSum>target) return false;
        if(currSum==target) return true;
        if(dp[i][currSum]!=-1) return dp[i][currSum];
        currSum+=nums[i];
        bool take=solve(i+1,nums,currSum,target,dp);
        currSum-=nums[i];
        bool notTake=solve(i+1,nums,currSum,target,dp);

        

        return dp[i][currSum]=take || notTake;
        
    }
    bool canPartition(vector<int>& nums) {
        
        vector<int>temp;
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0) return false;
        
        vector<vector<int>> dp(nums.size(), vector<int>(totalSum/2 + 1, -1));
        return solve(0,nums,0,totalSum/2,dp);
    }
};
