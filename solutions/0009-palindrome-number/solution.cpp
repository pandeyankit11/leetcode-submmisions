class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;

        int check=x;
        long long rev=0;
        while(x!=0){
            int rem = x%10;
            x/=10;
            rev=rev*10 + rem;
        }
        if(rev==check)
        return true;
        else{
            return false;
        }
        
    }
};
