class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> freq(n,0);
        vector<int> ds;
        helper(nums,ds,freq,ans);
        return ans;
    }
    
    void helper(vector<int> &nums,vector<int> &ds,vector<int> &freq, vector<vector<int>> &ans)
{
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0 ;i<nums.size(); ++i){
            if(freq[i] == 0){
                ds.push_back(nums[i]);
                freq[i] = 1;
                helper(nums,ds,freq,ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
        
    }
};