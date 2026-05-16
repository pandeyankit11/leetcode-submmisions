class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mid=nums.size()/2;
        if(nums.size()==1) return 0;
        if(mid==0){
            if(nums[mid]<nums[mid+1])
            return mid+1;
            else
            return mid;
        }
        if(mid==nums.size()-1){
            if(nums[mid]<nums[mid-1])
            return mid-1;
            else
            return mid;
        }

        while(!(nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1])){
        
        if(nums[mid]<=nums[mid-1] && nums[mid]<=nums[mid+1])
        mid=mid+1;
        if(nums[mid]>=nums[mid-1] && nums[mid]<=nums[mid+1])
        mid=mid+1;
        if(nums[mid]<=nums[mid-1] && nums[mid]>=nums[mid+1])
        mid=mid-1;

        if(mid==0)
        return 0;
        if(mid==nums.size()-1)
        return nums.size()-1;
    }
    return mid;



    }
};
