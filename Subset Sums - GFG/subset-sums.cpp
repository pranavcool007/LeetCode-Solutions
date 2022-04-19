// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sums;
        vector<int> c_sub;
        helper(0,c_sub,sums,arr);
        return sums;
    }
    
    void helper(int idx,vector<int> &c_sub,vector<int> &sums,vector<int> &nums){
        if(idx == nums.size()){
            int sum = 0;
            for(auto i: c_sub){
                sum += i;
            }
            sums.push_back(sum);
            return;
        }
        
        c_sub.push_back(nums[idx]);
        helper(idx+1,c_sub,sums,nums);
        c_sub.pop_back();
        
        helper(idx+1,c_sub,sums,nums);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends