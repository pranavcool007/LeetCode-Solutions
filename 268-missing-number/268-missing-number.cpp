class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans;
        
        for(int i=0; i<nums.size(); ++i){
            ++mpp[nums[i]];
        }
        
        for(int i =0; i<=nums.size(); ++i){  //find each value from[0,n] in map
            if(mpp.find(i) == mpp.end()){   
                ans = i;
                break;
            }
        }
        return ans;
    }
};