class Solution {
public:
    
    vector<int> rearrangeArray(vector<int>& nums) {
       int n=nums.size();
       vector<int>v1;
       vector<int>v2;
       for(int i=0;i<n;i++){
        if(nums[i]>0)
        v1.push_back(nums[i]);
        else
        v2.push_back(nums[i]);
       }
       nums.clear();
       for(int i=0;i<n/2;i++){
          nums.push_back(v1[i]);
          nums.push_back(v2[i]);

       }
        return nums;
    }
};
