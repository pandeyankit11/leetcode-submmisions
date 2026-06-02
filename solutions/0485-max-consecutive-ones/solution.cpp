class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int max_cnt=INT_MIN;
        if(n==1) {
            if(nums[0]==0) return 0;
            if(nums[0]==1) return 1;
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]==1)
            cnt++;
            
            max_cnt=max(max_cnt,cnt);
            if(nums[i]==0)
            cnt=0;

        }
        return max_cnt;

    }
};
