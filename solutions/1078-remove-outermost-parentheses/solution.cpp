class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int counter{0};
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            counter++;
            if(s[i]==')')
            counter--;
            if((s[i]=='(' && counter!=1) || (s[i]==')' && counter!=0))
            ans+=s[i];
        }
        return ans;
    }
};
