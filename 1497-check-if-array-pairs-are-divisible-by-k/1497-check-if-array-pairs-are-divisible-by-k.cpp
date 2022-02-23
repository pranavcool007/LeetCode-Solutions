class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        
        for(auto i: arr){
            if(i < 0){
                int rem = (k+(i%k))%k;    // done to get +ve rem for -ve nos
                ++mpp[rem];
            }
            else{
                int rem = i%k;
                ++mpp[rem];
            }  
            
        }
        
        for(auto i: arr){
            int rem = i%k;
            int freq = mpp[rem];
            
            if(rem == 0){
                if(freq%2 != 0){
                    return false;
                }
            }
            else if(2*rem == k){
                if(freq%2 != 0){
                    return false;
                }
            }
            else{
                int ofreq = mpp[k-rem];
                if(ofreq != freq){
                    return false;
                }
            }
        }
        return true;
    }
};