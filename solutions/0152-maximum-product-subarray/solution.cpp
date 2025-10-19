class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pMax=INT_MIN,p{1};
        int sMax=INT_MIN,s{1};
        
        for(int i=0;i<nums.size();i++){
            if(p==0)
                p=1;
            if(s==0)
            s=1;    
            
            p*=nums[i];
            s*=nums[nums.size()-i-1];
            pMax=max(p,pMax);
            sMax=max(s,sMax);
        }
        return max(pMax,sMax);

    }
};
