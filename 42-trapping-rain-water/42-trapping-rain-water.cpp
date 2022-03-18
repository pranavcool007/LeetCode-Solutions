class Solution {
public:
    int trap(vector<int>& height) {
//         // O(n) Time and O(n) space approach
//         int n = height.size();
//         vector<int> max_left(n);
//         vector<int> max_right(n);
//         max_left[0] = 0;
//         max_right[n-1] = 0;
//         int ans = 0;
        
//         for(int i=1; i<height.size(); ++i){
//             max_left[i] = max(max_left[i-1],height[i-1]);
//         }
//         for(int i=n-2; i>=0; --i){
//             max_right[i] = max(max_right[i+1],height[i+1]);
//         }
//         for(int i=0; i<height.size(); ++i){
//             int level = min(max_left[i],max_right[i]);
//             int water = level-height[i];
//             if(water >= 0){
//                 ans += water;
//             }
//         }
//         return ans;
//     }
        
        int n = height.size();
        int max_l = height[0];
        int max_r = height[n-1];
        int ans = 0;
        int l = 0;
        int r = n-1;
        while(l<r){
            if(max_l < max_r){
                ++l;
                int water = max_l-height[l];
                if(water > 0){
                    ans += water;
                }
                max_l = max(max_l,height[l]);
            }
            else{
                --r;
                int water = max_r-height[r];
                if(water > 0){
                    ans += water;
                }
                max_r = max(max_r,height[r]);
            }
        }
        return ans;
    }
};