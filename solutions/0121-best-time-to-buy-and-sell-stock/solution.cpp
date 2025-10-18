class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min_cost=prices[0];
       int max_profit{0};
       for(int i=1;i<prices.size();i++){
           min_cost=min(min_cost,prices[i]);
           max_profit=max(max_profit,prices[i]-min_cost);
       }
       
       return max_profit;
    }
};
