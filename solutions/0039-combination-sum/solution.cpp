class Solution {
public:
    void printSum(int i,vector<int> &temp, int target,vector<int> &arr,vector<vector<int>> &ans){
     if(i==arr.size()){
        if(target==0){
        ans.push_back(temp);
        
        }
        return;
     }
     if(arr[i]<=target){
     temp.push_back(arr[i]);
     printSum(i,temp,target-arr[i],arr,ans);
     temp.pop_back();
     }

     printSum(i+1,temp,target,arr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        printSum(0,temp,target,candidates,ans);
        return ans;
    }
};
