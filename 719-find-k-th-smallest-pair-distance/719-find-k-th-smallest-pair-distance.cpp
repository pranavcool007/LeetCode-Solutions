class Solution {
public:
    bool enough(int distance, vector<int>& nums, int k){
        int total_dis = 0;
        int n = nums.size();
        int j = 1;
        for(int i=0; i<n; ++i){
            while(j<n and nums[j]-nums[i] <= distance) ++j;
                --j;
            total_dis += j-i;
        }
        return total_dis >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int start = 0;
        int end = nums[n-1] - nums[0];     // diff of max and min
        while(start <= end){
            int mid = start + (end-start)/2;
            if(enough(mid,nums,k)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};
