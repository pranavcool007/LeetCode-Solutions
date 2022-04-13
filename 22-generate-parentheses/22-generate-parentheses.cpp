class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int openN = 0;
        int closedN = 0;
        string cans = "";
        helper(openN,closedN,cans,n,ans);
        return ans;
    }
    
    void helper(int openN,int closedN,string &cans,int n, vector<string> &ans){
        if(openN == closedN and openN == n){
            ans.push_back(cans);
            return;
        }
        
        if(openN < n){
            cans.push_back('(');
            helper(openN+1,closedN,cans,n,ans);
            cans.pop_back();
        }
        
        if(closedN < openN){
            cans.push_back(')');
            helper(openN,closedN+1,cans,n,ans);
            cans.pop_back();
        }
    }
};