class Solution {
public:


    long long modPow(long long base,long long exp,long long mod){
        long long ans=1;
        base=base%mod;

        while(exp>0){
            if(exp%2!=0)
            ans=(ans*base)%mod;

            base=(base*base)%mod;
            exp/=2;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        long long mod=1e9+7;
        int first=modPow(5,n-n/2,mod);
        int second=modPow(4,n/2,mod);
        return (1LL*first*second)%mod;
    }
};
