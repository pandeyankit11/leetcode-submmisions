class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v;
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[i]=nums[i];
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        bool check{0};
        while(check!=1){
            if(nums[i]+nums[j]==target){
                check=1;
                
            }
            else if(nums[i]+nums[j]>target)
            j--;
            else{
                i++;
            }
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==nums[i]){
            v.push_back(it->first);
            continue;
            }
        
            if(it->second==nums[j])
            v.push_back(it->first);
        }

        return v;



    }
};
