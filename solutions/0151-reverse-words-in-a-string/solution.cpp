class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string token="";
        stringstream ss(s);

        while(getline(ss,token,' ')){
            if(token!="")
            st.push(token);
        }

        if(st.empty()) return "";

        string result="";

        while(!st.empty()){
            result+=st.top()+" ";
            st.pop();
        }
        result.pop_back();
        return result;
    }
};
