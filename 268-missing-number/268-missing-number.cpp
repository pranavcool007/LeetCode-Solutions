class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum1 = 0,sum2 = 0;
        for(int i:nums){
            sum1 += i;
        }
        for(int i=0; i<=len; ++i){
            sum2 += i;
        }
        int ans = sum2-sum1;
        return ans;
    }
};