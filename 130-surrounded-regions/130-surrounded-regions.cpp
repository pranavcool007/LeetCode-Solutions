class Solution {
public:
    void dfs(int row, int col,vector<vector<char>> &board){
        int rows = board.size();
        int cols = board[0].size();
        if(row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] != 'O'){
            return;
        }
        board[row][col] = '1';
        dfs(row+1,col,board);
        dfs(row-1,col,board);
        dfs(row,col+1,board);
        dfs(row,col-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        //mark the unsurrounded regions(regions having 0 at the border)
        
        // first row and last row
        for(int j=0; j<cols; ++j){
            dfs(0,j,board);
            dfs(rows-1,j,board);
        }
        
        // first col and last col
        for(int i=1; i<rows-1; ++i){
            dfs(i,0,board);
            dfs(i,cols-1,board);
        }
                
        // now mark the surrounded regions from O -> X and unsurrounded 1 -> O
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }  
            }
        }
    }
};