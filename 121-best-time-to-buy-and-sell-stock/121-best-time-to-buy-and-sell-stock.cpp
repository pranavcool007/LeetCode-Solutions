class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min_left = prices[0];
        for(int i=1; i<prices.size(); ++i){
            profit = max(profit,prices[i]-min_left);     // maintain the left min
            min_left = min(min_left,prices[i]);
        }
        return profit;
    }
};