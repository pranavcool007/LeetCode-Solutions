class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cans;
        helper(0,target,cans,ans,candidates);
        return ans;
    }
    
    void helper(int idx,int target,vector<int> &cans,vector<vector<int>> &ans,vector<int> &candidates){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(cans);
                return;
            }
            return;
        }
        if(candidates[idx] <= target){
            cans.push_back(candidates[idx]);
            helper(idx,target - candidates[idx],cans,ans,candidates);
            cans.pop_back();
        }
        
        helper(idx+1,target,cans,ans,candidates);
    }
};