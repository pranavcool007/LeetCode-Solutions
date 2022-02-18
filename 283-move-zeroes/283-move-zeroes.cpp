class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left =-1;
        for(int right=0; right<nums.size(); ++right){
            if(nums[right] == 0){
                continue;
            }else{
                ++left;
                swap(nums[left],nums[right]);
            }
        }
        
    }
};