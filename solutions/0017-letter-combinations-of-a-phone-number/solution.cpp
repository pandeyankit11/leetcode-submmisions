class Solution {
public:

    unordered_map<char, string> mp = {

    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}

    };
    void solve(int i,string &temp,string &digits,vector<string>&ans){
    if(i==digits.length()){
        ans.push_back(temp);
        return;
    }

    for(int j=0;j<mp[digits[i]].size();j++){

        char ch=mp[digits[i]][j];
        temp.push_back(ch);
        solve(i+1,temp,digits,ans);
        temp.pop_back();
    }


    }
    vector<string> letterCombinations(string digits) {

        string temp="";
        vector<string>ans;
        solve(0,temp,digits,ans);
        return ans;

    }
};
