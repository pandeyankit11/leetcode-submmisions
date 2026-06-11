class Solution {
public:
    int solve(int i, int n, string& s, vector<int>& dp, vector<vector<bool>>& isPal) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int ans = 1e9;
        for (int end = i; end < n; end++) {
            // Use the precomputed table instead of re-calculating
            if (isPal[i][end]) {
                ans = min(ans, 1 + solve(end + 1, n, s, dp, isPal));
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        // 1. Precompute Palindromes in O(N^2)
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    isPal[i][j] = (len <= 2) ? true : isPal[i+1][j-1];
                }
            }
        }

        vector<int> dp(n, -1);
        return solve(0, n, s, dp, isPal) - 1;
    }
};
