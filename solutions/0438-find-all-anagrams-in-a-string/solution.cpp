class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.length();
        vector<int> result_indices;

        if (s.length() < k)
            return result_indices;

        vector<int> targetMap(26, 0);
        for (char c : p)
            targetMap[c - 'a']++;

        vector<int> currMap(26, 0);
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            currMap[s[right] - 'a']++;

            if (right >= k - 1) {

                if (targetMap == currMap) {
                    result_indices.push_back(left);
                }

                currMap[s[left] - 'a']--;
                left++;
            }
        }

        return result_indices;
    }
};
