class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int>lastOccurence(26,0);
      
        for(int i=0;i<s.size();i++){
            lastOccurence[s[i]-'a']=i;
        }

        stack<char>st;
        vector<bool> seen(26, false);

        for(int i=0;i<s.size();i++){

            if(seen[s[i]-'a']) continue;

            while(!st.empty() && st.top()>s[i] && lastOccurence[st.top()-'a']>i){
                seen[st.top()-'a']=false;
                st.pop();
            }

            st.push(s[i]);
            seen[s[i]-'a']=true;
        }

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
