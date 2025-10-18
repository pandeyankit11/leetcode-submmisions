class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter{0};
        int max_count{0};
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==1 && nums[i+1]==1)
            counter++;
            else{
                counter=0;
            }
            max_count=max(counter,max_count);

        }
        if(count(nums.begin(),nums.end(),0)==nums.size())
        return 0;

        return max_count+1;
    }
};
