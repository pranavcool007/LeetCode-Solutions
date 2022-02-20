class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mpp;
        
        for(auto i : nums){   // every no says seq starts from it
            mpp[i] = true;
        }
        for(auto i: nums){    // check incompatible strt points
            if(mpp.find(i-1) != mpp.end()){
                mpp[i] = false;
            }
        }
        int len = 0;
        int sp;              // only check for the srt points, and update
                             // max len and srt points
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