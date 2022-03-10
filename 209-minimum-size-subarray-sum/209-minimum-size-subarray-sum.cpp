class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum = 0;
        int ans = INT_MAX;
        int n = nums.size();
        
        while(j<n){
            sum += nums[j];
            
            if(sum < target){
                ++j;
            }
            else if (sum >= target){
                while(sum >= target){
                    sum -= nums[i];
                    ++i;
                }
                ans = min(ans,j-i+2);
                ++j;
            }
        }
        return ans == INT_MAX?0:ans;
    }
};