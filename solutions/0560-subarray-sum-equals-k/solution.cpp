class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter{0},preSum{0};
        map<int,int>m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            counter+=m[preSum-k];
            m[preSum]++;
            
            }
        return counter;
        }
    
};
