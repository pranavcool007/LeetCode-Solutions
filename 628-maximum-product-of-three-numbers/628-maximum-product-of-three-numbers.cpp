class Solution {
public:
    // O(nlogn) solution
/*    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
    }
*/
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> maxh;
        priority_queue<int,vector<int>,greater<int>> minh;
        int min1,min2,max1,max2,max3;
        for(auto num : nums){
            maxh.push(num);
            if(maxh.size() > 2){
                maxh.pop();
            }
        }
        min1 = maxh.top();  maxh.pop();
        min2 = maxh.top();  maxh.pop();
        // cout<<min1<<" "<<min2<<endl;
        for(auto num : nums){
            minh.push(num);
            if(minh.size() > 3){
                minh.pop();
            }
        }
        max3 = minh.top(); minh.pop();
        max2 = minh.top(); minh.pop();
        max1 = minh.top(); minh.pop();
        // cout<<max1<<" "<<max2<<" "<<max3;
        return max(max1*max2*max3, min1*min2*max1);
    }
};