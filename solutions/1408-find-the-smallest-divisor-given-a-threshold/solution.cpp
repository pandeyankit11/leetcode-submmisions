class Solution {
public:
    int resultSum(vector<int>&arr,int mid){
      int ans{0};
      for(int i=0;i<arr.size();i++){
         ans+=ceil((double)arr[i]/mid);
      }
      return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto max_num=max_element(nums.begin(),nums.end());
        int low=1; int high=*max_num;

        while(low<=high){
            int mid=(low+high)/2;
              if(resultSum(nums,mid)<=threshold)
              high=mid-1;
              else
              low=mid+1;
              
        }
        return low;
    }
};
