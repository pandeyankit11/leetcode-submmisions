class Solution {
public:
    string largestOddNumber(string num) {
        while((num.back()-'0')%2==0){
            num.erase(num.length()-1,1);
            if(num.empty())
            break;
            
        }
        return num;
    }
};
