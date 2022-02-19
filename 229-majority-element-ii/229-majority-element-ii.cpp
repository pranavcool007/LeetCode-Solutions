class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;         // store the count of each item
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
            ++mpp[nums[i]];
        }
        for(auto i: mpp){
            if(i.second > int(nums.size()/3)){  // check if count > n/2(floor)
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};