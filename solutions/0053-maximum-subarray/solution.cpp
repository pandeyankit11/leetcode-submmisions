class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int counter1{0};
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
            counter1++;
        }
        if(counter1==nums.size()){
            auto max_num=max_element(nums.begin(),nums.end());
            return *max_num;
        }

        int current_sum{0};
        int max_sum=INT_MIN;

        for(int i=0;i<nums.size();i++){
            current_sum+=nums[i];
            max_sum=max(max_sum,current_sum);

            if(current_sum<0)
            current_sum=0;
        }
        return max_sum;
    }
};
