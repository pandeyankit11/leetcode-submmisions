class Solution {
public:
   
        
    int beautySum(string s) {
        long long result{0};

        for(int i=0;i<s.length()-1;i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                if(i==j) continue;
                int min_freq=INT_MAX,max_freq=INT_MIN;
                for(auto f:freq){
                    if(f>0){
                    min_freq=min(min_freq,f);
                    max_freq=max(max_freq,f);
                    }
                }
                result+=max_freq-min_freq;
            }
        }
        return result;
    }
};
