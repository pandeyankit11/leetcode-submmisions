class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_five{0},count_ten{0};
        for(int i=0;i<bills.size();i++){

            if(bills[i]==5)
            count_five++;

            else if(bills[i]==10){
                count_five--;
                count_ten++;
            }

            else{
                if(count_ten>0 && count_five>0){
                count_ten--;
                count_five--;
                }
                else{
                    count_five-=3;
                }
            }

            if(count_five<0 || count_ten<0)
            return false;
        }
        return true;
    }
};
