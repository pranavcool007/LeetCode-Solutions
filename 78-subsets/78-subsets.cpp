class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,nums,{},ans);
        return ans;
    }
    
    void helper(int idx,vector<int> &nums, vector<int> cans,vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(cans);
            return;
        }
        cans.push_back(nums[idx]);
        helper(idx+1,nums,cans,ans);
        
        cans.pop_back();
        helper(idx+1,nums,cans,ans);
    }
};