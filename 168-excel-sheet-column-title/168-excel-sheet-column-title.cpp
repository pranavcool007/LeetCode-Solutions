class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int n = columnNumber;
        while(n > 0){
            n--;
            int curr_char = n%26;
            ans.push_back(curr_char + 'A');
            n /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};