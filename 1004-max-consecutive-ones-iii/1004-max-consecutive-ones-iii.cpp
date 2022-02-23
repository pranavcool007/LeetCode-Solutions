class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int ans = 0;
        int i = -1;
        int j = -1;
        while(i < (int)nums.size()-1){
            ++i;
            if(nums[i] == 0){
                count++;
            }
            
            while(count > k){
                ++j;
                if(nums[j] == 0){
                    --count;
                }
            }
            
            int len = i-j;
            ans = max(ans,len);
            
        }
        return ans;
    }
//     int longestOnes(vector<int>& nums, int k) {
//         int count = 0;
//         int ans = 0;
//         int i = -1;
//         int j = -1;
//         while(i<(int)nums.size()-1){
//             ++i;
//             if(nums[i] == 0){
//                 count++;
//             }
            
//             while(count > k){
//                 ++j;
//                 if(nums[j] == 0){
//                     --count;
//                 }
//             }
            
//             int len = i-j;
//             ans = max(ans,len);
            
//         }
//         return ans;
// }
};