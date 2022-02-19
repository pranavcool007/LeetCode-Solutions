class Solution {
public:
    // O(N) Time compl and O(N) Space compl
    vector<int> productExceptSelf(vector<int>& nums) {
/*      int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        
        for(int i=1; i<n; ++i){
            int temp = left[i-1]*nums[i];
            left[i] = temp;
        }
        for(int i=n-2; i>=0; --i){
            int temp = right[i+1]*nums[i];
            right[i] = temp;
        }
        
        for(int i=0; i<n; ++i){
            if(i == 0){
                ans[0] = right[1];
            }
            else if(i == n-1){
                ans[n-1] = left[n-2];
                
            }else{
            
            int prod = left[i-1]*right[i+1];
            ans[i] = prod;
        }
    }
        return ans;                           */
        
        int n = nums.size();
        vector<int> ans(n);
        int rprod = 1;
        
        ans[0] = nums[0];
        for(int i=1; i<n; ++i){
            int temp = ans[i-1]*nums[i];
            ans[i] = temp;
        }
        
        for(int i=n-1; i>0; --i){
            if(i == n-1){
                ans[i] = ans[i-1];
                rprod *= nums[i];
            }
            else{
                int temp = rprod*ans[i-1];
                ans[i] = temp;
                rprod *= nums[i];
            }
            
        }
        ans[0] = rprod;
        return ans;
        
}
};