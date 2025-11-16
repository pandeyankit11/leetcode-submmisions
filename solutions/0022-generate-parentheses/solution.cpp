class Solution {
public:
      void backtrack(int n,string &temp,vector<string> &ans,int ob_count,int cb_count){

        if(ob_count==n && cb_count==n){
           ans.push_back(temp);
           return;
        }

        if(ob_count<n){
            temp.push_back('(');
            backtrack(n,temp,ans,ob_count+1,cb_count);
            temp.pop_back();
        }
        if(cb_count<ob_count){
            temp.push_back(')');
            backtrack(n,temp,ans,ob_count,cb_count+1);
            temp.pop_back();
        }
        
      }
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        string temp="";
        backtrack(n,temp,ans,0,0);
        return ans;
    }
};
