class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int i=0,j=0;
        int n = s.length();
        int ans = INT_MIN;
        
        while(j<n){
            ++mpp[s[j]];
            
            if(j-i+1 == mpp.size()){
                ans = max(ans,j-i+1);
            }
            else if(j-i+1 > mpp.size()){
                while(j-i+1 > mpp.size()){
                    if(mpp[s[i]] == 1){
                        mpp.erase(s[i]);
                    }else{
                        --mpp[s[i]];
                    }
                    ++i;
                }
            }
            ++j;
        }
        return ans==INT_MIN?0:ans;;
    }
};