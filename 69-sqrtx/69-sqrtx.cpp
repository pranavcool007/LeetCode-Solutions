class Solution {
public:
    int mySqrt(int x) {
        long long start = 0;
        long long end = x+1.0;
        long long ans;
        while(start <= end){
            long long mid = start + (end-start)/2;
            if(mid*mid > x){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans-1;
    }
};