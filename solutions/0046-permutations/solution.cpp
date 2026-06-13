class Solution {
public:

    void solve(vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){

        if(temp.size()==nums.size()){
          ans.push_back(temp);
          return;
        }

        for(int j=0;j<nums.size();j++){

            if(nums[j]==20) continue;
            temp.push_back(nums[j]);
            int old=nums[j];
            nums[j]=20;
            solve(temp,ans,nums);
            nums[j]=old;
            temp.pop_back();
            
            
        }
     }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(temp,ans,nums);

        return ans;
    }
};
