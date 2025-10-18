class Solution {
public:
    bool check_pd(string &s,int i,int n){
    if(i>=n/2)
    return true;
    if(s[i]!=s[n-i-1])
    return false;
    return check_pd(s,i+1,n);
    }
    bool isPalindrome(string s) {
        string clean="";
        for(auto c:s){
            if(isalnum(c)){
                if(isupper(c))
                c=tolower(c);
                clean+=c;
            }
         
        }
        return check_pd(clean,0,clean.size());
    }
};
