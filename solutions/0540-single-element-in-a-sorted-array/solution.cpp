class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans{nums[nums.size()-1]};
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i])
            i++;
            else{
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};
