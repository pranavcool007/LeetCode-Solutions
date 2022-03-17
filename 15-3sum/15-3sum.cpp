class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size(); ++i){
            
            if(i>0 and nums[i] == nums[i-1]){
                continue;
            }
            
            int target = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
            
            if(nums[j] + nums[k] > target){
                --k;
            }
            else if(nums[j] + nums[k] < target){
                ++j;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                ++j;
                while(nums[j] == nums[j-1] and j<k){
                    ++j;
                }
            }
        }
        }
        return ans;
    }
};