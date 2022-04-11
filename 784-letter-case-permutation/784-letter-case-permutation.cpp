class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        lettercasepermutation(s,0,ans);
        return ans;
    }
    
    void lettercasepermutation(string s,int idx, vector<string> &ans){
        if(idx == s.length()){
            ans.push_back(s);
            return;
        }
        char ch = s[idx];
        if(isdigit(ch)){
            lettercasepermutation(s,idx+1,ans);
        }else{
            s[idx] = tolower(ch);
            lettercasepermutation(s,idx+1,ans);
            
            s[idx] = toupper(ch);
            lettercasepermutation(s,idx+1,ans);
        }
        
    }
};