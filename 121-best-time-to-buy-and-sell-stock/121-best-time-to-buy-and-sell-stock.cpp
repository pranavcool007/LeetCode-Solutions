class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minl = prices[0];
        for(int i=1; i<prices.size(); ++i){
            profit = max(profit,prices[i]-minl);
            minl = min(minl,prices[i]);
        }
        return profit;
    }
};