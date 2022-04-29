class Solution {
public:
    bool isValid(int row,int col,int rows,int cols,vector<vector<int>>& grid){
        if(row<0 || col<0 || row>=rows || col>=cols || grid[row][col] != -1){
            return false;
        }
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<cols; ++j)
            {
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
                if(grid[i][j] == 0){
                    grid[i][j] = -1;
                }
            }
        }
        if(q.size() == rows*cols) return -1;
        
        int dist = 0;
        while(!q.empty()) {
            int count = q.size();
            ++dist;
            for(int i=0; i<count; ++i){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                if(isValid(row+1,col,rows,cols,grid)){    // take care of names  cols != col
                    q.push({row+1,col});
                    grid[row+1][col] = 1;
                }
                if(isValid(row-1,col,rows,cols,grid)){
                    q.push({row-1,col});
                    grid[row-1][col] = 1;
                }
                if(isValid(row,col+1,rows,cols,grid)){
                    q.push({row,col+1});
                    grid[row][col+1] = 1;
                }
                if(isValid(row,col-1,rows,cols,grid)){
                    q.push({row,col-1});
                    grid[row][col-1] = 1;
                }
            }
            
    }
        return dist-1;
    }
};