class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> cans = {};
        helper(0,nums,cans,ans);
        return ans;
    }
    
    void helper(int idx,vector<int> &nums, vector<int> &cans,vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(cans);
            return;
        }
        
        cans.push_back(nums[idx]);
        helper(idx+1,nums,cans,ans);
        cans.pop_back();
        
        while(idx+1 < nums.size() and nums[idx] == nums[idx+1]){
            ++idx;
        }
        helper(idx+1,nums,cans,ans);
        
    }
};