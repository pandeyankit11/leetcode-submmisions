class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        vector<int>vec;

        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        for(int i=0;i<s.length();i++){
            int end=m[s[i]];

            for(int j=i+1;j<end;j++){
             end=max(end,m[s[j]]);
            }
            vec.push_back(end-i+1);
            i=end;
        }
        return vec;
    }
};
