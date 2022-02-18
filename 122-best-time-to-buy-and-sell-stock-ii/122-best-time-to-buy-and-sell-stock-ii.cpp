class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bd = 0;               // buying date
        int sd = 0;               // selling date
        int profit = 0;
        
        for(int i=1; i<prices.size(); ++i){
            if(prices[i] >= prices[i-1]){      // inc sd till a dip comes
                ++sd;
            }else{
                profit += prices[sd]-prices[bd];  // collect the prev peak profits
                bd = sd = i;                      // move sd and bd to current dip
            }
        }
        profit += prices[sd]-prices[bd];        // to collect last peak as no dip will be 
                                                // further there
        return profit;
    }
};