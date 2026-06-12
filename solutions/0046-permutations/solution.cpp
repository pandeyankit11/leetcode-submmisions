class Solution {
public:

    void solve(vector<int>&vis, vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){

        if(temp.size()==nums.size()){
          ans.push_back(temp);
          return;
        }

        for(int j=0;j<nums.size();j++){

            if(!vis[j]){
            vis[j]=1;
            temp.push_back(nums[j]);
            solve(vis,temp,ans,nums);
            temp.pop_back();
            vis[j]=0;
            }
            
        }
     }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int>temp;
        vector<vector<int>>ans;
        vector<int>vis(nums.size(),0);
        solve(vis,temp,ans,nums);

        return ans;
    }
};
