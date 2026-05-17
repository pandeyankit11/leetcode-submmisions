class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto max_num=max_element(weights.begin(),weights.end());
        int l=*max_num;
        int r= accumulate(weights.begin(),weights.end(),0);

        int ans=-1;

        while(l<=r){
            int mid=(l+r)/2;

            int requiredDays{1};
            int curr_weight{0};

            for(int i=0;i<weights.size();i++){
                if(curr_weight+weights[i]<=mid){
                    curr_weight+=weights[i];
                }

                else{
                    requiredDays++;
                    curr_weight=weights[i];
                    
                }
            }
            
               
            

            if(requiredDays<=days){
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
