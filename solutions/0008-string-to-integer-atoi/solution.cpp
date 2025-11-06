class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long long res{0};

        while(s[i]==' ' && i<s.size())i++;

        if(i==s.length()) return 0;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
        i++;

        while(i<s.size() && isdigit(s[i])){
            res=res*10 + (s[i]-'0');

            if(sign*res>INT_MAX) return INT_MAX;
            if(sign*res<INT_MIN) return INT_MIN;
            i++;
        }
         return sign*res;
    }
};
