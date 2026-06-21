class Solution {
public:
    int firstUniqChar(string s) {
        int ans=-1;
        unordered_map<char,int>m;
        queue<char>q;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            q.push(s[i]);
        }
        int j=0;
        while(!q.empty()){
            if(m[q.front()]==1){
                ans=j;
                break;
            }
            q.pop();
            j++;
            
        }

        return ans;
    }
};
