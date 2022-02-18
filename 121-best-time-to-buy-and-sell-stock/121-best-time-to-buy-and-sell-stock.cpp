class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int o_profit =0;
        int lsf = INT_MAX;
        int pist;
        for(int i=0; i<prices.size(); ++i){
            if(lsf > prices[i]){
                lsf = prices[i];
            }
            pist = prices[i]-lsf;
    
            o_profit = max(o_profit,pist);
        }
        return o_profit;
    }
};