class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        long x = n & (long(n)-1);
        if(x == 0){
            return true;
        }
        return false;
    }
};