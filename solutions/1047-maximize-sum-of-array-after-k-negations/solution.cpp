class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        while (pq.top() <= 0 && k > 0) {
            int x = pq.top();

            pq.pop();

            pq.push(-x);
            k--;
        }

        int sum = 0;
        int min_num = pq.top();
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        if (k == 0 || (k > 0 && k % 2 == 0))
            return sum;
        return sum - (2 * min_num);
    }
};
