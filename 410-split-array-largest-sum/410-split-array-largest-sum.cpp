class Solution {
public:
    bool feasible(int max_sum,vector<int> &nums,int Pieces){
        int total = 0;
        int pieces = 1;
        for(auto num: nums){
            total += num;
            if(total > max_sum){
                total = num;
                pieces += 1;
                if(pieces > Pieces){
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);
        while(start <= end){
            int mid = start + (end-start)/2;
            if(feasible(mid,nums,m)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};