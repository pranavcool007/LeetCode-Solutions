class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(row<0 || col<0 || row>=rows || col>=cols || grid[row][col] !=0){
            return;
        }
        grid[row][col] = 2;   // that land is visited
        dfs(row+1,col,grid);
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row,col-1,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows == 0) return 0;
        
        // flood fill the islands touching the boundary
        
        // first row and last row
        for(int j=0; j<cols; ++j){
            if(grid[0][j] == 0)
            dfs(0,j,grid);
            
            if(grid[rows-1][j] == 0)
            dfs(rows-1,j,grid);
        }

        // first col and last col
        for(int i=1; i<rows-1; ++i){
            if(grid[i][0] == 0)
            dfs(i,0,grid);
            
            if(grid[i][cols-1] == 0)
            dfs(i,cols-1,grid);
        }
        
        // Now count the islands covered with water
        int count = 0;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j] == 0){
                    ++count;
                    dfs(i,j,grid);
                }
            }
        }
        
        return count;
    }
};