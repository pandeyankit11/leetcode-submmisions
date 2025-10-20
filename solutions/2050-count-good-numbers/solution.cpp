class Solution {
public:
        long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

        int countGoodNumbers(long long n) {
            const int MOD = 1e9 + 7;
        long long power_four,power_five;
        if(n%2==0){
            power_four=n/2;
            power_five=n/2;
        }
        else{
            power_four=floor((double)n/2);
            power_five=ceil((double)n/2);
        }

        


long long ans = (modPow(4, power_four, MOD) * modPow(5, power_five, MOD)) % MOD;
return ans;

    }
};
