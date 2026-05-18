class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long time=0;
        int l=1;
        int r=piles[piles.size()-1];
        int ans=-1;
        
        
        while(l<=r){
            int mid=(l+r)/2;
            for(int i=0;i<piles.size();i++){
                time+= ceil((double)piles[i]/mid);
            }

            if(time<=h){
            ans=mid;
            time=0;
            r=mid-1;
            }
            else {
            time=0;
            l=mid+1;
            }

            
            }
         return ans;
    }
};
