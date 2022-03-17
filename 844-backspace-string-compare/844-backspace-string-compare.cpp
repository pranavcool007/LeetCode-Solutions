class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0;
        int p = 0;
        int n = s.length();
        int m = t.length();
        
        for(int i=0; i<n; ++i){
            if(s[i] == '#'){
                --k;
                if(k<0) k = 0;
            }
            else{
                s[k] = s[i];
                ++k;
            }
        }
        for(int i=0; i<m; ++i){
            if(t[i] == '#'){
                --p;
                if(p<0) p = 0;
            }
            else{
                t[p] = t[i];
                ++p;
            }
        }
        if(k != p){
            return false;
        }else{
            for(int i=0; i<k; ++i){
                if(s[i] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};