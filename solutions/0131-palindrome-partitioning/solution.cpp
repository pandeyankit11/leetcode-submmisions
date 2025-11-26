class Solution {
public:
    bool isPalindrome(string str){
        bool check{true};
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-i-1]){
                check=false;
                break;
            }
        }
        return check;
    }
    void getAllParts(string s,vector<string> &temp,vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(isPalindrome(part)){
            temp.push_back(part);
            getAllParts(s.substr(i+1),temp,ans);
            temp.pop_back();

            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        getAllParts(s,temp,ans);

        return ans;
    }
};
