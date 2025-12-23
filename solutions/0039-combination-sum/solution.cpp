class Solution {
public:
    void printSum(int i,vector<int> &temp, int target,vector<int> &arr,vector<vector<int>> &ans){
     
        if(target==0){
        ans.push_back(temp);
        return;
        }
     
     for(int j=i;j<arr.size();j++){
            
            if(arr[j]>target) break;

            temp.push_back(arr[j]);
            printSum(j,temp,target-arr[j],arr,ans);
            temp.pop_back();
        }    
      
     
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>temp;
        printSum(0,temp,target,candidates,ans);
        return ans;
    }
};
