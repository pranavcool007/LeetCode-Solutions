class Solution {
public:
    // O(n^k backtracking solution)
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cans;
        int start = 1;
        helper(start,cans,ans,n,k);
        return ans;
    }
    
    void helper(int start, vector<int> &cans,vector<vector<int>> &ans,int n,int k){
        if(cans.size() == k){
            ans.push_back(cans);
            return;
        }
        
        for(int i= start; i<=n; ++i){
            cans.push_back(i);
            helper(i+1,cans,ans,n,k);
            cans.pop_back();
        }
    }
};