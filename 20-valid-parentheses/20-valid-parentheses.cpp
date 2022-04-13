class Solution {
public:
/*  best way is to make mappings of opening and closing brackets, opening as +ve no and same 
    no as -ve in closing.
    then we have to check 2 things for valid parenthesis:
    1. at the end of the string stk shd be empty.
    2. at the time of popping check that the stack shd be >0 in order to pop something from 
       it. eg to handle cases like (, (( , ([{ .
*/
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