class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int curr_diff=0;
        int min_diff=INT_MAX;

        int left=0;

        for(int right=0;right<nums.size();right++){
            curr_diff=nums[right]-nums[left];

            if(right>=k-1){
                min_diff=min(min_diff,curr_diff);

                curr_diff=0;
                left++;
            }
        }
        return min_diff;

    }
};
