class Solution {
public:
    void combination(int i,vector<int> &arr,vector<int> &temp,vector<vector<int>> &ans){

        
            ans.push_back(temp);
            

        for(int j=i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1]) continue;
            

            temp.push_back(arr[j]);
            combination(j+1,arr,temp,ans);
            temp.pop_back();
        }    
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<int>temp;
        vector<vector<int>>ans;
        
        combination(0,nums,temp,ans);
        
        return ans;   
    }
};
