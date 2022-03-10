class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;
        int curSum = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        
        int n = nums.size();
        
        while(i<n){
            
            curSum += nums[i];
            
            if(curSum == k){
                count++;
            }
            if(mpp.find(curSum-k) != mpp.end()){
                count += mpp[curSum-k];
            }
            ++mpp[curSum];
            ++i;
     
        }
        return count;
    }
};