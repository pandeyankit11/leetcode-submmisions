class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        

        int left=0;
        long long max_sum=0;
        long long curr_sum=0;

        unordered_map<int,int>m;

        for(int right=0;right<nums.size();right++){
            curr_sum+=nums[right];
            m[nums[right]]++;

            if(right>=k-1){

                if(m.size()==k)
                max_sum=max(max_sum,curr_sum);

                curr_sum-=nums[left];
                m[nums[left]]--;

                if(m[nums[left]]==0)
                m.erase(nums[left]);

                left++;
            }
        }

        return max_sum;
    }
};
