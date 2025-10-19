class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec(2);
        
            auto it1 =find(nums.begin(),nums.end(),target);
            auto it2 = find(nums.rbegin(),nums.rend(),target);
        if(it1!=nums.end()){
            vec[0]=it1-nums.begin();
            vec[1]=nums.size()-(it2-nums.rbegin())-1;
        }
        else{
            vec[0]=-1;
            vec[1]=-1;
        }
        return vec;

        
    }
};
