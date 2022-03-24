class Solution {
public:
//     int enough(int distance, vector<int>& nums, int k){
//         int total_dis = 0;
//         int n = nums.size();
//         int j = 1;
//         for(int i=0; i<n; ++i){
//             while(j<n and nums[j]-nums[i] <= k) ++j;
//                 --j;
//             total_dis += j-i;
//         }
//         return total_dis;
//     }
//     int smallestDistancePair(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
        
//         // int n = nums.size();
//         // int start = 0;
//         // int end = nums[n-1] - nums[0];     // diff of max and min
//         // while(start <= end){
//         //     int mid = start + (end-start)/2;
//         //     if(enough(mid,nums,k)){
//         //         end = mid-1;
//         //     }
//         //     else{
//         //         start = mid+1;
//         //     }
//         // }
//         return enough(5,nums,k);
//     }
// };
        bool ok(int mid , vector<int>& a , int& k){
        int n=a.size();
        int j=1;
        int total=0;
        for(int i=0;i<n;i++){
            while(j<n && a[j]-a[i]<=mid) j++;
            j--;
            int x=(j-i);
            total+=x;
        }
        return (total>=k);
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=nums[n-1]-nums[0];
        int l=0;
        int r=diff;
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,nums,k))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};