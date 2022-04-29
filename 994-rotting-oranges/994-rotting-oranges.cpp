class Solution {
public:
    bool isValid(int row,int col,int rows,int cols,vector<vector<int>> &grid){
        if(row<0 || col<0 || row>=rows|| col>=cols|| grid[row][col] != 1){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh_or = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<cols; ++j)
            {
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    ++fresh_or;
                }
            }
        }
        if(fresh_or == 0) return 0;
        int time = 0;
        while(!q.empty()){
            int count = q.size();
            ++time;
            for(int i=0; i<count; ++i){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
            
                if(isValid(row+1,col,rows,cols,grid)){
                    q.push({row+1,col});
                    grid[row+1][col] = 2;
                    --fresh_or;
                }
                if(isValid(row-1,col,rows,cols,grid)){
                    q.push({row-1,col});
                    grid[row-1][col] = 2;
                    --fresh_or;
                }
                if(isValid(row,col+1,rows,cols,grid)){
                    q.push({row,col+1});
                    grid[row][col+1] = 2;
                    --fresh_or;
                }
                if(isValid(row,col-1,rows,cols,grid)){
                    q.push({row,col-1});
                    grid[row][col-1] = 2;
                    --fresh_or;
                }
            }
            
        }
        return fresh_or == 0? time-1 : -1;
    }
};