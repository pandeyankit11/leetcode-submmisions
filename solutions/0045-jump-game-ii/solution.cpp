class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size();
        if (n == 1)
            return 0;
        vector<int>vec(n,0);

        for(int i=0;i<n;i++){
            vec[i]=i+nums[i];
        }

        int jumps = 0;
        int l = 0;
        int r = 0;
        int farthest=0;

        while(r<n-1){

            for(int i=l;i<=r;i++){
                farthest=max(farthest,vec[i]);
            }

            l=r+1;
            r=farthest;
            jumps++;
        }

        return jumps;
    }
};
