class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cans;
        vector<vector<string>> ans;
        helper(0,s,cans,ans);
        return ans;
    }
    
    void helper(int idx,string s,vector<string> &cans,vector<vector<string>> &ans){
        if(idx == s.length()){
            ans.push_back(cans);
            return;
        }
        
        for(int i=idx; i<s.size(); ++i){
            if(isPalindrome(s.substr(idx,i-idx+1))){
                cans.push_back(s.substr(idx,i - idx + 1));
                helper(i+1,s,cans,ans);
                cans.pop_back();
            }
        }
        
    }
    
    bool isPalindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};