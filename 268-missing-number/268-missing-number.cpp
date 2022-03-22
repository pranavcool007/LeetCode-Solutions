class Solution {
public:
    int missingNumber(vector<int>& nums) {
//         {
//         unordered_map<int,int> mpp;
//         int ans;
        
//         for(int i=0; i<nums.size(); ++i){
//             ++mpp[nums[i]];
//         }
        
//         for(int i =0; i<=nums.size(); ++i){
//             if(mpp.find(i) == mpp.end()){
//                 ans = i;
//                 break;
//             }
//         }
//         return ans;
//     }
        // O(1) Space and O(n) Time
        int len = nums.size();
        int sum1 = 0,sum2 = 0;
        for(int i:nums){
            sum1 += i;
        }
        for(int i=0; i<=len; ++i){
            sum2 += i;
        }
        int ans = sum2-sum1;
        return ans;
    }
};