class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {

        vector<int> vec(time + 1, 0);

        for (auto clip : clips) {
            int start = clip[0];
            int end = clip[1];

            if (start < time) {
                vec[start] = max(vec[start], end);
            }
        }

        int jumps = 0;
        int l = 0;
        int r = 0;
        int farthest = 0;

        while (r < time) {

            for (int i = l; i <= r; i++) {

                farthest = max(farthest, vec[i]);
            }

            if (farthest <= r) {
                return -1;
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};
