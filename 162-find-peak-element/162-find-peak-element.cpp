class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;      // in case of one element
        
        int n = nums.size();
        
        // check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;    
        if(nums[n-1] > nums[n-2]) return n-1;
        
        // search in the remaining array
        int start = 1;   
        int end = n-2;

        while(start <= end){
            int mid = start + (end-start)/2;
         
            
            if(nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]){
                return mid;
            }
            else if(nums[mid+1] > nums[mid]){
                start = mid+1;
            }
            else if(nums[mid-1] > nums[mid]){
                end = mid-1;
            }
        }
        return -1;
    }
};