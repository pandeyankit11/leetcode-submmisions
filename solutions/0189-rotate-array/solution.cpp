class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>b(n);
       for(int i=0;i<n;i++){
           b[(i+k)%n]=nums[i];
       }
       b.swap(nums);
    }
};
