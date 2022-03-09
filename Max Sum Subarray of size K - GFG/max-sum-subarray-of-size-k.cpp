// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &Arr , int N){
        int ans = INT_MIN;
        int sum = 0;
        int i = 0;
        int j = 0;
        while(j<N){
            sum = sum + Arr[j];
            
            if(j-i+1 < k){
                ++j;
            }
            else if(j-i+1 == k){
                ans = max(sum,ans);
                sum -= Arr[i];
                ++i;
                ++j;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends