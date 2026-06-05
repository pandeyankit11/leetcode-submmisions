class Solution {
public:

    double Pow(double base,long long exp){

        if(exp<0){
            base=1/base;
            exp=-exp;
        }
        double ans=1;
        while(exp>0){
            if(exp%2!=0)
            ans=ans*base;

            base=base*base;
            exp/=2;
        }

        return ans;
      
    }
    double myPow(double x, int n) {
        
       return Pow(x,n);
    }
};
