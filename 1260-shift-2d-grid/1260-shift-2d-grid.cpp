class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int> (n,0));
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int arr_val = i*n + j;
                int shifted = (arr_val + k) % (m*n);
                int new_row = shifted/n;
                int new_col = shifted%n;
                ans[new_row][new_col] = grid[i][j];
            }
        }
        return ans;
        
        
    }
};