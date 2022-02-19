class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        /* the trick here is every no range is [1,n] so every no
            can be used as idx by subs 1 and we make the value at 
            that idx -ve, if same no comes in arr it will map to 
            same idx and we push that in the ans */
        
        for(int i=0; i<nums.size(); ++i){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){
                ans.push_back(abs(nums[i]));
            }
            nums[index] = -nums[index];
        }
        return ans;
    }
};