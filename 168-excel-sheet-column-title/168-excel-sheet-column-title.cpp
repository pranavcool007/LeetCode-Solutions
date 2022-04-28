class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int n = columnNumber;
        while(n > 0){
            n--;
            int curr_char = n%26;
            ans = char(curr_char + 'A') + ans;
            n /= 26;
        }
        return ans;
    }
};