class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); ++i){
            ++mpp[nums[i]];
        }
        
        for(int j=1; j<=nums.size(); ++j){
            if(mpp.find(j) == mpp.end()){
                ans.push_back(j);
            }
        }
        return ans;
    }
};