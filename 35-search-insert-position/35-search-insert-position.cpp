class Solution {
public:
    /* if the target is present in the array binary search finds it
    and if its not present the start pointer always end at the position 
    where the target was supposed to be present */
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};