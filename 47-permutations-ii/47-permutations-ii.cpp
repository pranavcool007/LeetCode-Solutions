class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto num: nums){
            mpp[num]++;
        }
        vector<vector<int>> ans;
        vector<int> cans;
        int k = nums.size();
        helper(mpp,cans,ans,k);
        return ans;
    }
    
    void helper(unordered_map<int,int> &mpp,vector<int> &cans,vector<vector<int>> &ans,int k){
        if(cans.size() == k){
            ans.push_back(cans);
            return;
        }
        
        for(auto i: mpp){
            int no = i.first;
            int freq = i.second;
            if(freq > 0){
            cans.push_back(no);
            mpp[no]--;
            helper(mpp,cans,ans,k);
            mpp[no]++;
            cans.pop_back();   
            }
        }
        
    }
};