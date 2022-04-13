class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int dir = 0, top = 0, left = 0;
        int down = n-1;
        int right = m-1;
        int i;
        
        while(left<=right and top<=down){
            if(dir == 0){
                for(i=left; i<=right; ++i)
                    ans.push_back(matrix[top][i]);
                ++top;
            }   
            else if(dir == 1){
                for(i=top; i<=down; ++i){
                    ans.push_back(matrix[i][right]);
                }
                --right;
            }
            else if(dir == 2){
                for(i=right; i>=left; --i){
                    ans.push_back(matrix[down][i]);
                }
                --down;
            }
            else if(dir == 3){
                for(i=down; i>=top; --i){
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};