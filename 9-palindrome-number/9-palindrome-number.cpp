class Solution {
public:
    bool isPalindrome(int x) {
        string no = to_string(x);
        int i = 0;
        int j = no.size()-1;
        while(i<j){
            if(no[i] != no[j]){
                return false;
            }
            ++i;--j;
        }
        return true;
    }
};