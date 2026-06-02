class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return ;

        for(int i=0,j=1;j<n;j++){
            if(nums[i]==0 && nums[j]!=0){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                i++;
            }
            if((nums[i]!=0 && nums[j]==0) || (nums[i]!=0 && nums[j]!=0))
            i++;
        }
    }
};
