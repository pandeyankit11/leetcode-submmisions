class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int i,j,k=nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>>vec;
       
        while(k>=2){
            if(k<nums.size()-1 && nums[k]==nums[k+1]) {
                k--;
                continue;
            };
        int target=-nums[k];
        i=0;
        j=k-1;
        while(i<j){
            int pair_sum=nums[i]+nums[j];
            if(pair_sum==target){
            vector<int>temp={nums[i],nums[j],nums[k]};
            
            vec.push_back(temp);
            j--;
            }
            if(pair_sum>target)
            j--;
            if(pair_sum<target)
            i++;
        }
        k--;
        }

    set<vector<int>>s;
    s.insert(vec.begin(),vec.end());
    vec.clear();
    
    for(auto it=s.begin();it!=s.end();it++){
        vec.push_back(*it);
    }
        return vec;
        
    }
};
