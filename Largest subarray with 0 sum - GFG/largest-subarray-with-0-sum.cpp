// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        int max_len = 0;
        int i = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        
        while(i<n){
            sum += a[i];
            auto it = mpp.find(sum);
            if(it != mpp.end()){
                int len = i - mpp[sum];
                max_len = max(max_len,len);
            }else{
                mpp[sum] = i;
            }
            ++i;
        }
        return max_len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends