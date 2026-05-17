class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        
        int l=1;
        auto max_num=max_element(bloomDay.begin(),bloomDay.end());
        int r=*max_num;
        int ans=-1;

        while(l<=r){
            int mid=(l+r)/2;

            int curr_count{0};
            int bouquet{0};
            for(int i=0;i<n;i++){
               if(bloomDay[i]<=mid ){
               curr_count++;

               if(curr_count==k){
                curr_count=0;
                bouquet++;
               }
             }
             else{
                curr_count=0;
             }
            }

            if(bouquet>=m){
                ans=mid;
                r=mid-1;
            }
            else{
            
            l=mid+1;
            }
         }
         return ans;

    }
};
