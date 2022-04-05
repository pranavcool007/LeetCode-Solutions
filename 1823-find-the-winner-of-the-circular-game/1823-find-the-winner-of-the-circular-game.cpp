class Solution {
public:
    //Game of Execution - Josephus Problem 
    int findTheWinner(int n, int k) {
        if(n == 1){
            return 1;
        }
        int x = findTheWinner(n-1,k);
        int y = (x+k-1)%(n)+1;          // 1 based indexing
                                        // 0 based indexing  (x+k)%n
        return y;
    }
};