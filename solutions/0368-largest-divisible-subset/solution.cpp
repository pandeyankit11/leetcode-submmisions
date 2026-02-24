class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int LisLastIdx=0;
        int LIS=1;
        vector<int >dp(n,1);
        vector<int>prevIdx(n,-1);
        vector<int>result;

        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prevIdx[i]=j;
                }
            }
            if(dp[i]>LIS){
              LIS=dp[i];
              LisLastIdx=i;
            }

        }
        while(LisLastIdx!=-1){
            result.push_back(nums[LisLastIdx]);
            LisLastIdx=prevIdx[LisLastIdx];
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
