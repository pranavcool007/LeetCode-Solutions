class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        
        for(int i =0; i<nums.size(); ++i){
            ++mpp[nums[i]];
        }
        
        for(auto t: mpp){
            if(t.second > 1){
                return true;
            }
        }
        return false;
    }
};