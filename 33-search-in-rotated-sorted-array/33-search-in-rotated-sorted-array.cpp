class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            if((nums[start] == nums[mid]) and (nums[end] == nums[mid])){
                ++start;
                --end;
            }
            else if(nums[mid] <= nums[end]){
                if(target > nums[mid] and target <= nums[end]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
            else if(nums[start] <= nums[mid]){                 // or direct else
                if(target < nums[mid] and target >= nums[start]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
        return -1;
    }
};