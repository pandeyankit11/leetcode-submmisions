class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        int minLen=min(strs[0].length(),strs[strs.size()-1].length());
        string ans="";
        for(int i=0;i<minLen;i++){
            if(strs[0][i]==strs[strs.size()-1][i])
            ans+=strs[0][i];
            else
            break;
        }
        return ans;
        
    }
};
