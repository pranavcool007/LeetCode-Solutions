class Solution {
public:
    bool isValid(char val, vector<vector<char>> &board,int row,int col){
        // row check
        for(int i=0; i<board[0].size(); ++i){
            if(board[row][i] == val){
                return false;
            }
        }
        //col check
        for(int i=0; i<board.size(); ++i){
            if(board[i][col] == val){
                return false;
            }
        }
        // 3*3 matrix check
        int sub_mat_i = (row / 3) * 3;
        int sub_mat_j = (col / 3) * 3;
        for(int i=0; i<3; ++i)
        {
            for(int j=0; j<3; ++j)
            {
                if(board[sub_mat_i + i][sub_mat_j + j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool sudokuSolver(vector<vector<char>> &board,int row,int col){
        if(row == board.size()) return true;
        
        int next_row,next_col ;
        
        if(col == board[0].size()-1)
        {
            next_col = 0;
            next_row = row+1;
        }
        else
        {
            next_col = col + 1;
            next_row = row;
        }
        
        if(board[row][col] != '.')
        {
            return sudokuSolver(board,next_row,next_col);
        }
        else{
            for(char po='1'; po<='9'; ++po)
            {
                if(isValid(po,board,row,col))
                {
                    board[row][col] = po;
                    if(sudokuSolver(board,next_row,next_col))
                    {
                        return true;
                    }
    
                    board[row][col] = '.';
                }
            } 
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        
        int row = 0; 
        int col = 0;
        
        sudokuSolver(board,row,col);
        
    }
};