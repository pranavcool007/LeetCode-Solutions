class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mpp;
        
        for(auto i : nums){
            mpp[i] = true;
        }
        for(auto i: nums){
            if(mpp.find(i-1) != mpp.end()){
                mpp[i] = false;
            }
        }
        int len = 0;
        int sp;
        for(auto i: nums) {
            if(mpp[i] == true){
                int tlen = 1;
                int tsp = i;
                while(mpp.find(tsp+tlen) != mpp.end()){
                    ++tlen;
                }
                if(tlen>len){
                    len = tlen;
                    sp = tsp;
                }
                
            }
        }
        return len;
    }
};