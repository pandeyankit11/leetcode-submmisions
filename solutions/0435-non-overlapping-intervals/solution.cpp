class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int remove_count = 0;

        int lastValidEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastValidEnd) {
                remove_count++;
            } else {
                lastValidEnd = intervals[i][1];
            }
        }

        return remove_count;
    }
};
