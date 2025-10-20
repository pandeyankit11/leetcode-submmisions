class Solution {
public:
    int romanToInt(string s) {
        int ans{0};
        for(int i=0;i<s.length();i++){

            if(s[i]=='I'){
                if(s[i+1]=='V' && i<s.length()-1){
                ans+=4;
                i++;
                }
                else if(s[i+1]=='X' && i<s.length()-1){
                ans+=9;
                i++;
                }
                else
                ans+=1;
            }

            else if(s[i]=='V')
            ans+=5;

            else if(s[i]=='X'){
                if(s[i+1]=='L' && i<s.length()-1){
                ans+=40;
                i++;
                }
                else if(s[i+1]=='C' && i<s.length()-1){
                ans+=90;
                i++;
                }
                else
                ans+=10;
            }
            
            else if(s[i]=='L')
            ans+=50;

            else if(s[i]=='C'){
                if(s[i+1]=='D' && i<s.length()-1){
                ans+=400;
                i++;
                }
                else if(s[i+1]=='M' && i<s.length()-1){
                ans+=900;
                i++;
                }
                else
                ans+=100;
            }
            
            else if(s[i]=='D')
            ans+=500;

            else if(s[i]=='M')
            ans+=1000;

        }
        
        return ans;
    }
};
