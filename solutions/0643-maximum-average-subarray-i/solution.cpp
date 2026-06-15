class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        double curr_sum=0;

        double max_val=INT_MIN;

        for(int right=0;right<nums.size();right++){
            curr_sum+=nums[right];

            if(right>=k-1){
                max_val=max(max_val,curr_sum);

                curr_sum-=nums[left];
                left++;
            }
        }

        return max_val/k;
    }
};
