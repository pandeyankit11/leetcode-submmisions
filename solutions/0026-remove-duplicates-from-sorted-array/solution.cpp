class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        int k=s.size();
        vector<int>nums_new(k);
        int j{0};
        for(auto it=s.begin();it!=s.end() && j<k;it++,j++){
            nums_new[j]=*it;
        }
        nums.swap(nums_new);
        return k;
    }
};
