class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;

        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2=st.back(); st.pop_back();
                int num1=st.back(); st.pop_back();

                if(token=="+") st.push_back(num1+num2);
                else if(token=="-") st.push_back(num1-num2);
                else if(token=="*") st.push_back(num1*num2);
                else if(token=="/") st.push_back(num1/num2);
            }
            else{
                st.push_back(stoi(token));
            }
        }

        return st[0];
    }
};
