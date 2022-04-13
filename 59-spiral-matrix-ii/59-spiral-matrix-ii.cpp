class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n,0));
        int dir = 0, top = 0, left = 0;
        int down = n-1;
        int right = n-1;
        int i;
        int j = 1;
        
        while(left<=right and top<=down){
            if(dir == 0){
                for(i=left; i<=right; ++i)
                    ans[top][i] = j++;
                ++top;
            }   
            else if(dir == 1){
                for(i=top; i<=down; ++i){
                    ans[i][right] = j++;
                }
                --right;
            }
            else if(dir == 2){
                for(i=right; i>=left; --i){
                    ans[down][i] = j++;
                }
                --down;
            }
            else if(dir == 3){
                for(i=down; i>=top; --i){
                    ans[i][left] = j++;
                }
                ++left;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};