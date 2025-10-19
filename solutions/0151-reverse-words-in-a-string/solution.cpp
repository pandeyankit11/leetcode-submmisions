class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        string ans="";
        for(int i=0;i<s.length();i++){
            string temp="";
            while(s[i]!=' ' && i<s.length()){
                temp+=s[i];
                i++;
            }
            if(!temp.empty())
            vec.push_back(temp);
            
            while(s[i]==' ' && i<s.length()){
                i++;
            }
            i--;

        }
        reverse(vec.begin(),vec.end());
        
        
        for(auto &ch :vec){
            ans+=ch+" ";
        }   
        ans.erase(ans.length()-1,1);

        
        return ans;
    }
};
