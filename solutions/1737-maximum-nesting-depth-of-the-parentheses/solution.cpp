class Solution {
public:
    int maxDepth(string s) {
        int curr{0};
        int max_count=INT_MIN;

        for(int i=0;i<s.length();i++){

            if(s[i]=='(')
                curr++;
            if(s[i]==')')
            curr--;

            max_count=max(curr,max_count);
            
        }
        return max_count;
    }
};
