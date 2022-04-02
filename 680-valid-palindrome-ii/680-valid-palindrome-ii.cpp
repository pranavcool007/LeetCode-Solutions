class Solution {
public:
    
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