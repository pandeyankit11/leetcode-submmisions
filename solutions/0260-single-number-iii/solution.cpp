class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         vector<int>ans;
        
        int xor_all=0;
        for(auto x:nums){
            xor_all^=x;
        }
        
        long long mask=xor_all &(-(long long)xor_all);
        
        vector<int>a;
        vector<int>b;
        
        for(int i=0;i<nums.size();i++){
            if((nums[i]&mask)!=0)
            a.push_back(nums[i]);
            else{
                b.push_back(nums[i]);
            }
        }
        int ans1=0;
        int ans2=0;
        for(auto x:a){
            ans1^=x;
        }
        for(auto x:b){
            ans2^=x;
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        
        return ans;
    }
};
