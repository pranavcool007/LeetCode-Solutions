class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int> (n,0));
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int arr_val = i*n + j;      // 2d to 1d convert
                int shifted = (arr_val + k) % (m*n);  // shifting by k on 1d array
                int new_row = shifted/n;    // 2d row of 1d idx
                int new_col = shifted%n;    // 2d col of 1d idx
                ans[new_row][new_col] = grid[i][j];
            }
        }
        return ans;
        
        
    }
};