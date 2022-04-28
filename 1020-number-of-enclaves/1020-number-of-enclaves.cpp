/* this ques has same logic as surrounded region problem. The regions having 1 on the boundary
   are the regions through which we can cross the boundary of the grid so not included those.
   only 1's region that are surrounded by 0's we need to count.
*/
class Solution {
public:
    void dfs(int row, int col,vector<vector<int>> &grid){
        int rows = grid.size();
        int cols = grid[0].size();
        if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != 1){
            return;
        }
        grid[row][col] = 0;
        dfs(row+1,col,grid);
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row,col-1,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        //mark the unsurrounded regions(regions having 0 at the border)
        
        // first row and last row
        for(int j=0; j<cols; ++j){
            dfs(0,j,grid);
            dfs(rows-1,j,grid);
        }
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        // first col and last col
        for(int i=1; i<rows-1; ++i){
            dfs(i,0,grid);
            dfs(i,cols-1,grid);
        }
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        int count = 0;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j] == 1){
                    ++count;
                } 
            }
        }
        return count;
    }
};