class Solution {
public:
    void solve(int i,vector<int> &arr,vector<int> &temp,set<vector<int>>&s){
        if(i==arr.size()){
            s.insert(temp);
            return;
        }

       temp.push_back(arr[i]);
       solve(i+1,arr,temp,s);
       temp.pop_back();
       solve(i+1,arr,temp,s);
            
          
         
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        set<vector<int>>s;
        solve(0,nums,temp,s);
        for(auto it=s.begin();it!=s.end();it++){
            ans.push_back(*it);
        }
        
        return ans;   
    }
};
