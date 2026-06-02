class Solution {
public:
    bool check(vector<int>& nums) {
        int dec_cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
            dec_cnt++;

            if(dec_cnt>1)
            return false;
        }
        if(dec_cnt==0) return true;
        if(nums[nums.size()-1]<=nums[0]) return true;

        return false;

    }
};
