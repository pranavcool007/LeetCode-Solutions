class Solution {
    int first_position(vector<int> &nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int index = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(target == nums[mid]){
                index = mid;
                end = mid-1;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return index;    
    }
    int last_position(vector<int> &nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int index = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(target == nums[mid]){
                index = mid;
                start = mid+1;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return index;    
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = first_position(nums,target);
        int second = last_position(nums,target);
        ans.push_back(first);
        ans.push_back(second);
        return ans;
        
    }
};