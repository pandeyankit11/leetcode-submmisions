class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;

        int slow = 0;
        int fast = 1;
        set<vector<int>>s;

        while (fast < nums.size()) {
            int diff = nums[fast] - nums[slow];

            if (diff == k) {
                s.insert({nums[slow],nums[fast]});
                fast++;
                slow++;
            }

            else if (diff < k) {
                fast++;
            } 

            else {
                slow++;
            }

            if (slow == fast)
                fast++;
        }
        return s.size();
    }
};
