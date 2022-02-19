class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans;
        for(int i=0; i<nums.size(); ++i){
            ++mpp[nums[i]];
        }
        for(auto i: mpp){
            if(i.second > int(nums.size()/2)){
                ans = i.first;
            }
        }
        return ans;
    }
};