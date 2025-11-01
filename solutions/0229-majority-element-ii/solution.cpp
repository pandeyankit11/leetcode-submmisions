class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int limit=nums.size()/3;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second >limit)
            ans.push_back(it->first);
        }
        return ans;
    }
};
