class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(row<0 || col<0 || row>=rows || col>=cols || grid[row][col] != '1'){
            return;
        }
        grid[row][col] = '2'; // marked for visited land
        dfs(row+1,col,grid);
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row,col-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        if(rows == 0) return 0;    // no element present in the grid
        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<cols; ++j)
            {
                
                if(grid[i][j] == '1')
                {
                    dfs(i,j,grid);
                    ++count;
                }
            }
        }
        return count;
    }
};