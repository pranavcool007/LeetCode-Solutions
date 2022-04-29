class Solution {
public:
    bool isValid(int row,int col,int rows,int cols){
        if(row<0 || col<0 || row>=rows || col>= cols){
            return false;
        }
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(rows,vector<int> (cols,-1));// initialize the matrix to all -1 
        
/* Pushing the start nodes which are 0 to the queue and making the ans = 0 for 0 cells as 
   distance from 0 cell to itself is 0
*/
        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<cols; ++j)
            {
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        
        // bfs traversal
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
/* check for the neighbours if they are valid and not visited mark them as visited add to the 
   queue and update the ans.
   if they already visited it means ans is already marked with some nearest 0 
*/
            if(isValid(i+1,j,rows,cols) and ans[i+1][j] == -1){
                q.push({i+1,j});
                ans[i+1][j] = ans[i][j] + 1;
            }
            
            if(isValid(i-1,j,rows,cols) and ans[i-1][j] == -1){
                q.push({i-1,j});
                ans[i-1][j] = ans[i][j] + 1;
            }
            
            if(isValid(i,j+1,rows,cols) and ans[i][j+1] == -1){
                q.push({i,j+1});
                ans[i][j+1] = ans[i][j] + 1;
            }
            
            if(isValid(i,j-1,rows,cols) and ans[i][j-1] == -1){
                q.push({i,j-1});
                ans[i][j-1] = ans[i][j] + 1;
            }
        }
        return ans;
    }
};