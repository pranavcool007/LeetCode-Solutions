class Solution {
public:
// this works for +ve nos and all -ves no cannot be a pow of 2 ovio, best is to directly
// return the results without storing anything to avoid overflow (range given)
    bool isPowerOfTwo(int n) {
        return n > 0 and !(n &(n-1));
    }
};