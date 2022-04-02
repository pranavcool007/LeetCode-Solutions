class Solution {
public:
    // only one char removal is allowed
    /* eg aaaz in this i -> a and j -> z, so either we can remove
    a and check if aaz is palindrome or not or we can remove z and
    check if aa if palindrome or not. if any of the above cases are 
    true then return true or return false
    */
    
    bool validPalindrome(string s) {
        int j = s.length()-1;
        int i = 0;
        while(i < j){
            if(s[i] == s[j]){       
                ++i;
                --j;
            }
            else{
                string s1 = s.substr(i,j-i);
                string s2 = s.substr(i+1,j-i);
                reverse(s1.begin(),s1.end());
                reverse(s2.begin(),s2.end());
                return (s.substr(i,j-i) == s1) or 
                       (s.substr(i+1,j-i) == s2);
            }
        }
        return true;
    }
};