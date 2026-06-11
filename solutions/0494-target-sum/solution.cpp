class Solution {
public:

    int solve(int i,int currSum,vector<int>&nums,int target){
        if(i==nums.size()) {
            if(currSum==target)
            return 1;
            else
            return 0;
        }

        
        int add=solve(i+1,currSum+nums[i],nums,target);
        
        int sub=solve(i+1,currSum-nums[i],nums,target);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
       return solve(0,0,nums,target);
    }
};
