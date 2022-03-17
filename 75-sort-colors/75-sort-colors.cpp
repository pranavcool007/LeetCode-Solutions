class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int k = nums.size()-1;
        while(i <= k){
            if(nums[i] == 1){               // 1 will be instered into j to i-1 region
                ++i;                        // as count of 1 is inc in this region ++i
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[k]);      // 2 will be inserted into k+1 to end region
                --k;                        // as count of 2 is inc in this region hence --k
            }
            else{
                swap(nums[i],nums[j]);
                ++j;                         // as 0 is inserted into 0 to j-1 region
                ++i;                         // after swapping the no came would be 1 so ++i
            }
        }
    }
};