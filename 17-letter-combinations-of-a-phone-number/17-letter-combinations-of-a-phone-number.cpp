class Solution {
public:
    unordered_map<int,string> mpp{{2,"abc"}, {3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ans;
        string cans;
        helper(0,cans,ans,digits);
        return ans;
    }
    
    void helper(int idx, string &cans,vector<string> &ans,string digits){
        if(idx == digits.size()){
            ans.push_back(cans);
            return;
        }
        
        string choices = mpp[digits[idx] - '0'];
        for(char ch: choices){
            cans.push_back(ch);
            helper(idx+1,cans,ans,digits);
            cans.pop_back();
        }
    }
};