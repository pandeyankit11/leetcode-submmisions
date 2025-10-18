class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool check{0};
        for(int i=0;i<nums.size();i++){
            if(nums[i]-i!=0){
            check=1;
            return i;
            }
        }
        
        return nums.size();
    }
};
