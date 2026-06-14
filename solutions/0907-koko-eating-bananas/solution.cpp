class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            long long time = 0;
            for (int i = 0; i < piles.size(); i++) {
                time += ceil((double)piles[i] / mid);
            }

            if (time <= h) {
                ans = mid;

                r = mid - 1;
            } else {

                l = mid + 1;
            }
        }
        return ans;
    }
};
