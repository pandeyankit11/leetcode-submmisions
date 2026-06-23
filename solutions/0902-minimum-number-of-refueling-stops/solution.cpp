class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int max_reach = startFuel;
        priority_queue<int> max_heap;
        int ans = 0;
        int i = 0;
        int n = stations.size();

        while (max_reach < target) {

            while (i < n && stations[i][0] <= max_reach) {
                max_heap.push(stations[i][1]);
                i++;
            }

            if (max_heap.empty()) {
                return -1;
            }

            max_reach += max_heap.top();
            max_heap.pop();
            ans++;
        }

        return ans;
    }
};
