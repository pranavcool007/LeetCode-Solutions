class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int i=0,j=0;
        int ans = INT_MIN;
        unordered_map<int,int> mpp;
        int n = fruits.size();
        
        while(j<n){
            ++mpp[fruits[j]];
            
            if(mpp.size()<k){
                ++j;
                if(j==n){
                    return j-i;
                }
            }
            else if(mpp.size() == k){
                ans = max(ans,j-i+1);
                ++j;
            }
            else if(mpp.size() > k){
                while(mpp.size() > k){
                    if(mpp[fruits[i]] == 1){
                        mpp.erase(fruits[i]);
                    }
                    else{
                        --mpp[fruits[i]];
                    }
                    ++i;
                }
                ++j;
            }
        }
        return ans;
    }
};