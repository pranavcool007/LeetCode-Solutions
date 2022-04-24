class Solution {
public:
    string addBinary(string a, string b) {
        string A = a;
        string B = b;
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        int len = max(A.size(),B.size());
        int carry = 0;
        string res = "";
        for(int i=0; i<len; ++i){
            int digitA;
            int digitB;
            if(i < A.size()) digitA = A[i] - '0'; else digitA = 0; 
            if(i < B.size()) digitB = B[i] - '0'; else digitB = 0;
            int total = digitA + digitB + carry;
            carry = total / 2;
            total = total % 2;
            res = to_string(total) + res;
        }
        if(carry){
            res = "1" + res;
        }
        return res;
    }
};