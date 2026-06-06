class Solution {
public:
    bool consecutiveSetBits(int n) {
         int x = n & (n >> 1);
         int cnt = __builtin_popcount(x);
        return cnt==1;
         
         
    }
};
