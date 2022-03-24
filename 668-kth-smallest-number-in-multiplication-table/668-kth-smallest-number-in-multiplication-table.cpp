class Solution {
public:
    bool enough(int num,int m , int n, int k){
        int total = 0;
        for(int i=1; i<=m; ++i){
            total += min(num/i,n);
        }
        return total >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int start = 1;
        int end = m*n;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(enough(mid,m,n,k)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};