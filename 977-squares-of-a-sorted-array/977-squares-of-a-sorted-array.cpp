class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int i = 0;        // i to srting of nums
        int j = n-1;     // j to end of nums
        int k = n-1;     // k point to the ans vector
        while(k>=0){
            if(abs(nums[i])>abs(nums[j])){  // if no is greater so will be squares
                                            // also the greatest ele will be at extremes
                ans[k] = nums[i]*nums[i];
                ++i;
                --k;
            }else{
                ans[k] = nums[j]*nums[j];
                --j;
                --k;
            }
        }
        return ans;
    }
};