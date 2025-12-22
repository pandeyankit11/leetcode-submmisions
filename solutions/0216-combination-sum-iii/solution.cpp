class Solution {
public:
    void solve(int i,vector<int> nums,vector<int> &temp,vector<vector<int>> &ans,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<nums.size();j++){
            if(nums[i]>target) break;
            temp.push_back(nums[j]);
            solve(j+1,nums,temp,ans,target-nums[j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};

        vector<int>temp;
        vector<vector<int>>ans;

        solve(0,nums,temp,ans,n);
        vector<vector<int>>final_ans;
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()==k)
            final_ans.push_back(ans[i]);
        }
        return final_ans;

    }
};
