class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int count=0;
        int left=0;

        int curr_prod=1;

        for(int right=0;right<nums.size();right++){
            curr_prod*=nums[right];

            while(curr_prod>=k){
                curr_prod/=nums[left];
                left++;
            }

            count+=(right-left+1);
        }

        return count;


    }
};
