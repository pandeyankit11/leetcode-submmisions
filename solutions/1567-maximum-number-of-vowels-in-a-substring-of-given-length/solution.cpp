class Solution {
public:
        bool isVowel(char c){
        return  (c== 'a' || c== 'e' || c== 'i' || c== 'o' || c== 'u');
        }
    int maxVowels(string s, int k) {
        int left=0;
        int max_len=INT_MIN;
        int curr_vowel_len=0;

        for(int right=0;right<s.length();right++){
            if(isVowel(s[right])){
                curr_vowel_len++;
            }

            if(right>=k-1){
                max_len=max(max_len,curr_vowel_len);
                if(isVowel(s[left])) curr_vowel_len--;
                left++;
            }
        }
        return max_len;


    }
};
