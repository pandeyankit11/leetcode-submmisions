class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;

        int max_len = INT_MIN;
        int left = 0;

        unordered_map<char, int> m;

        for (int right = 0; right < s.length(); right++) {

            m[s[right]]++;

            while (m[s[right]] > 1) {
                m[s[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

