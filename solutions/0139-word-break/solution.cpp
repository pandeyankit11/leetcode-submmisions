class Solution {
public:
    unordered_set<string> st;
    bool solve(int i, string& s, vector<int>& dp) {
        if (i == s.size())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (int end = i; end < s.size(); end++) {
           
            string curr = s.substr(i, end-i+1);

            if (st.count(curr)){
              if(solve(end+1 ,s, dp)){
                return dp[i] = true;
              }
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto str : wordDict) {
            st.insert(str);
        }

        vector<int> dp(301, -1);

        return solve(0, s, dp);
    }
};
