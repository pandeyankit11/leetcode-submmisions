class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>b(nums.size());
    for(int x=0;x<nums.size();x++){
        for(int i=0;i<nums.size();i++){
            b[i]=nums[(i+x)%nums.size()];
        }
        if(is_sorted(b.begin(),b.end()))
        return true;
    }
    return false;
    }
};
