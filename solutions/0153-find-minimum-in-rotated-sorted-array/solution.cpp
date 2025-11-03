class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX,l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[l]<=nums[mid]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else {
            ans=min(ans,nums[mid]);
            r=mid-1;
            }
        }
        return ans;

    }
};
