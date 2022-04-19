class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if( dfs(0,i,j,rows,cols,board,word) ) {
                    return true;
                }
            }
        }
        
        return false;
    
    }
    
    bool dfs(int i,int r,int c,int rows,int cols,vector<vector<char>>& board,string &word){
            if(i == word.length()){
                return true;
            }
            if(r < 0 || c < 0 || r >= rows || c >= cols || word[i] != board[r][c] || 
               board[r][c] == '*'){
                return false;
            }
            
            char ch = board[r][c];
            board[r][c] = '*';
            bool res = (dfs(i+1,r+1,c,rows,cols,board,word) or 
                        dfs(i+1,r-1,c,rows,cols,board,word) or
                        dfs(i+1,r,c+1,rows,cols,board,word)  or
                        dfs(i+1,r,c-1,rows,cols,board,word));
            
            board[r][c] = ch;
            return res;
            
        }
    
    
};