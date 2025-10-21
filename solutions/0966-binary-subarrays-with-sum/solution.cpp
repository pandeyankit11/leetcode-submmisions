class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int counter{0},preSum{0};
        map<int,int>m;
        m[0]=1;

        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            counter+=m[preSum-goal];
            m[preSum]++;
        }
        return counter;
    }
};
