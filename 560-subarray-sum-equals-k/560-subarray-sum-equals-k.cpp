class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> mpp;
        int i = 0;
        int sum = 0;
        mpp[0]=1;
        while(i < nums.size()){
            
            sum += nums[i];
            
            if(mpp.find(sum-k) != mpp.end()){
                count += mpp[sum-k];
                ++mpp[sum];
                
            }
            else{
                ++mpp[sum];
            }
            i++;
        }
    
        return count;
        
    }
};