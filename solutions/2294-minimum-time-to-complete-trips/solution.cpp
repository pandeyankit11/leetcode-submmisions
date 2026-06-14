class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long l=*min_element(time.begin(),time.end());
        long long r=(long long)l*totalTrips;
        long long ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;

            long long trips=0;
            for(int i=0;i<n;i++){
                trips+= floor((double)mid/time[i]);
            }

            if(trips>=totalTrips){
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
