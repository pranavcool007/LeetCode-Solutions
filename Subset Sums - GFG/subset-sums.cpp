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
        int c_sum;
        helper(0,c_sum,sums,arr);
        return sums;
    }
    
    void helper(int idx,int &c_sum,vector<int> &sums,vector<int> &nums){
        if(idx == nums.size()){
            sums.push_back(c_sum);
            return;
        }
        
        c_sum += nums[idx];
        helper(idx+1,c_sum,sums,nums);
        c_sum -= nums[idx];
        
        helper(idx+1,c_sum,sums,nums);
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