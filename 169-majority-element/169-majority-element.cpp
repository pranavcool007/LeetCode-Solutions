class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;         // store the count of each item
        int ans;
        for(int i=0; i<nums.size(); ++i){
            ++mpp[nums[i]];
        }
        for(auto i: mpp){
            if(i.second > int(nums.size()/2)){  // check if count > n/2(floor)
                ans = i.first;
            }
        }
        return ans;
    }
};