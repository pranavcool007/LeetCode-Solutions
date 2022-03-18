class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 0;
        int i = 1;
            while(true){
                n -= i;
                if(n < 0){
                    break;
                }
                rows++;
                ++i;
            }
        return rows;
    }
};