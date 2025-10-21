class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_res{0};
        for(auto num :nums){
            xor_res^=num;
        }
        return xor_res;

    }
};
