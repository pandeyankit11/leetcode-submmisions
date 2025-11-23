class Solution {
public:
    void combination(int idx,vector<int> &arr,int target,vector<int> &temp,vector<vector<int>> &ans){

        
            if(target==0){
            ans.push_back(temp);
            return;
            }
        for (int j = idx; j < (int)arr.size(); j++) {
            // skip duplicates at same level
            if (j > idx && arr[j] == arr[j - 1]) continue;

            if (arr[j] > target) break; // pruning

            temp.push_back(arr[j]);
            combination(j + 1, arr, target - arr[j], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
     
     vector<int>temp;
     vector<vector<int>>ans;
     combination(0,candidates,target,temp,ans);
     
     
     return ans;   
    }
};
