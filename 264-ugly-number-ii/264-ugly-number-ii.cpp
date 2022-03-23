class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(1,1);
        int i=0,j=0,k=0;
        while(nums.size() < n){
            int num = min(nums[i]*2, min(nums[j]*3 ,nums[k]*5 ));
            nums.push_back(num);
            if(nums.back() == nums[i]*2) ++i;
            if(nums.back() == nums[j]*3) ++j;
            if(nums.back() == nums[k]*5) ++k;
        }
        return nums.back();
    }
};