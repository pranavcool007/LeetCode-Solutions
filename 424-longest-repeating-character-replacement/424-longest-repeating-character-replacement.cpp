class Solution {
    int max_freq(unordered_map<char,int> &mpp){
        int temp = INT_MIN;
        for(auto i: mpp){
            temp = max(temp,i.second);
        }
        return temp;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int i=0,j=0;
        int n = s.length();
        int ans = INT_MIN;
        int mx_fr = 0;
        
        while(j<n){
            ++mpp[s[j]];
            
            mx_fr = max_freq(mpp);
            // if(j-i+1 - mx_fr <= k){
            //     
            // }
            
            if(j-i+1 - mx_fr > k){
                while(j-i+1 - mx_fr > k){
                    --mpp[s[i]];
                    ++i;
                    mx_fr = max_freq(mpp);
                }
            }
            ans = max(ans,j-i+1);
            ++j;
        }
        return ans;
    }
};