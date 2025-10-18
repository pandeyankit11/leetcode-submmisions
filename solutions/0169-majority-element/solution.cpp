class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int counter{0};
        for(auto it=m.begin();it!=m.end();it++){
            counter=max(counter,it->second);
        }
        int ans;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==counter){
                ans=it->first;
                break;
            }
            
        }
        return ans;
        
    }
};
