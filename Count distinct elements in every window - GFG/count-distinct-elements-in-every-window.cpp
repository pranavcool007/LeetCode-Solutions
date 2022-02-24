// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        for(int i =0; i<k-1; ++i){
            ++mpp[A[i]];
        }
        
        int i = k-1;
        int j = 0;
        while(i<n){
            ++mpp[A[i]];
            ans.push_back(mpp.size());
            
            if(mpp[A[j]] == 1){
                mpp.erase(A[j]);
            }else{
                --mpp[A[j]];
            }
            ++i;
            ++j;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends