class Solution {
public:
    unordered_map<char,int> mpp{{'[',1}, {'{',2},{'(',3},{']',-1}, {'}',-2},{')',-3}};
    bool isValid(string s) {
        stack<int> stk;
        for(char ch : s){
            if(mpp[ch] > 0){
                stk.push({mpp[ch]});
            }
            else{
                if(stk.size() >0 and stk.top() == abs(mpp[ch])){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(stk.size() == 0){
            return true;
        }
        return false;
    }
};