class Solution {
public:
    void solve(int i,vector<int> &temp, vector<int> &nums,vector<vector<int>> &ans){
        
            ans.push_back(temp);
        

        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            solve(j+1,temp,nums,ans);
            temp.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,temp,nums,ans);
        return ans;
    }
};
