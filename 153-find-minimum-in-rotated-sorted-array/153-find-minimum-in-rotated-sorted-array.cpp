class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = nums.size()-1;
        int min_index;
        while(start <= end){
            if(nums[start] <= nums[end]){
                min_index = start;
                break;
            }
            int mid = start + (end-start)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;            // doubt
            if(nums[mid] < nums[next] and nums[mid] < nums[prev]){
                min_index = mid;
                break;
            }
            else if(nums[mid] <= nums[end]){
                end = mid-1;
            }
            else if(nums[start] <= nums[mid]){
                start = mid+1;
            }
        }
        return nums[min_index];
        
    }
};