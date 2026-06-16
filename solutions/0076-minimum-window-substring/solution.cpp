class Solution {
public:

    bool isValid(vector<int>& targetMap,vector<int>&currMap){
        for(int i=0;i<128;i++){
            if(targetMap[i]!=0 && currMap[i]<targetMap[i])
            return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int left=0;
        string ans="";
        int startIdx=-1;
        vector<int>targetMap(128,0);
        vector<int>currMap(128,0);
        int min_len=INT_MAX;
        for(int i=0;i<t.length();i++){
            char c=t[i];
            targetMap[c]++;
        }

        for(int right=0;right<s.length();right++){
            char c=s[right];
            currMap[c]++;
            
           while(isValid(targetMap,currMap)){
            if(right-left+1<min_len){
            startIdx=left;
            min_len=min(min_len,right-left+1);
            }
            char c=s[left];
            currMap[c]--;
            left++;

           }
           
          
        }
        if(startIdx==-1)
        return "";

        return s.substr(startIdx,min_len);

    }
};
