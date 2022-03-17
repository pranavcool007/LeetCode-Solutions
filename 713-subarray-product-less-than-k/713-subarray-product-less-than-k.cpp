class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int prod = 1;
        int count = 0;
        int j=0,i=0;
        
        while(j<nums.size()){
            prod *= nums[j];
            
            if(prod >= k){
                while(prod >= k){
                    prod /= nums[i];
                    ++i;
                }
            }
            count += j-i+1;
            ++j;
        }
        return count;
    }
};