class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long sum=0;
        int i=0;
        while(s[i]=='1' && i<nums.size()){
            sum+=nums[i];
            i++;
        }
        for(int j=i;j<nums.size();j++){
            if(s[j]=='1'){
                sum+=nums[j-1];
                int min_ele=nums[j-1];
                int l=j;
                int r=j;
                while(s[r]!='0' && r<nums.size()){
                    min_ele=min(min_ele,nums[r]);
                    sum+=nums[r];
                    r++;
                }
                sum-=min_ele;
                j=r-1;
            }
        }
        return sum;
    }
};
