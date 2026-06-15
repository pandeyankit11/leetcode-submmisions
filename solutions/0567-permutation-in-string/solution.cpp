class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if(s2.size() < k) return false;
        
        // Use a vector of size 26 for O(1) lightning-fast comparisons
        vector<int> targetMap(26, 0);
        for(int i = 0; i < k; i++){
            targetMap[s1[i] - 'a']++; // Map 'a' to index 0, 'b' to 1, etc.
        }
        
        vector<int> currMap(26, 0);
        int left = 0; // The missing engine piece!

        for(int right = 0; right < s2.size(); right++){
            currMap[s2[right] - 'a']++;

            if(right >= k - 1){

                // Vector comparison is perfectly valid and incredibly fast
                if(targetMap == currMap) 
                    return true;

                currMap[s2[left] - 'a']--;
                left++;
            }
        }

        return false;
    }
};
