class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int odd_count = 0;
        int left = 0;

        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0)
                odd_count++;

            while (odd_count > k) {
                if (nums[left] % 2 != 0)
                    odd_count--;

                left++;
            }

            ans += (right - left + 1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
};
