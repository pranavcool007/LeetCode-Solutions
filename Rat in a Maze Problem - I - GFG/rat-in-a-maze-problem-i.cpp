// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 1){
            dfs(0,0,n,"",ans,m);
        }
        
        return ans;
    }
    
    void dfs(int row, int col, int n,string c_path, vector<string> &ans,vector<vector<int>> &m){
        if(row == n-1 and col == n-1){
            ans.push_back(c_path);
            return;
        }
        // Down
        if(row+1 < n and m[row+1][col] != 0){
            m[row][col] = 0;
            dfs(row+1,col,n,c_path + "D",ans,m);
            m[row][col] = 1;
        }
        
        // Left
        if(col-1 >= 0 and m[row][col-1] != 0){
            m[row][col] = 0;
            dfs(row,col-1,n,c_path + "L",ans,m);
            m[row][col] = 1;
        }
        
        // Right
        if(col+1 < n and m[row][col+1] != 0){
            m[row][col] = 0;
            dfs(row,col+1,n,c_path + "R",ans,m);
            m[row][col] = 1;
        }
         
        // Up
        if(row-1 >= 0 and m[row-1][col] != 0){
            m[row][col] = 0;
            dfs(row-1,col,n,c_path + "U",ans,m);
            m[row][col] = 1;
        }
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends