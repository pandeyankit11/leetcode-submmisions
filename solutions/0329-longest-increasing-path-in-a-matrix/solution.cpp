class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    int solve(int row, int col, vector<vector<int>>& matrix, int n, int m,
              vector<vector<int>>& dp) {
        if (row < 0 || row >= n || col < 0 || col >= m)
            return -1e9;

        if (dp[row][col] != -1)
            return dp[row][col];

        int ans = 1;

        for (int k = 0; k < 4; k++) {
            int nr = row + dir[k][0];
            int nc = col + dir[k][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                matrix[nr][nc] > matrix[row][col]) {
                ans=max(ans,1+solve(nr, nc, matrix, n, m, dp));
            }
        }

        return dp[row][col] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = -1e9;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix, n, m, dp));
            }
        }
    return ans;
    }
};
