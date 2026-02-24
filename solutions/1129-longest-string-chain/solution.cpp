class Solution {
public:

    bool isSubsequence(string a,string b){
        if(b.size()-a.size()!=1)
        return false;
         int i{0},j{0};

         while(i<a.size() && j<b.size()){
            if(a[i]==b[j])
            i++;
            j++;
         }
         if(i==a.size())
         return true;

         return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        int LIS=1;
        vector<int>dp(n,1);

        sort(words.begin(),words.end(),[](string &a,string &b){
        return a.size()<b.size();
        });

        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(dp[i]<dp[j]+1 && isSubsequence(words[j],words[i])){
                    dp[i]=dp[j]+1;

                }
            }
            if(dp[i]>LIS)
            LIS=dp[i];
        }

        return LIS;
    }
};
