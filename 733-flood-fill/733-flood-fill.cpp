class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int color,int newColor){
        int rows = image.size();
        int cols = image[0].size();
        if(i<0 || j<0 || i>=rows || j>= cols|| image[i][j] != color){
            return;
        }
        image[i][j] = newColor;
        dfs(i+1,j,image,color,newColor);
        dfs(i-1,j,image,color,newColor);
        dfs(i,j+1,image,color,newColor);
        dfs(i,j-1,image,color,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color =  image[sr][sc];
//It would cause StackOverFlow since we would be going back and forth to change the color to NewColor even though it's already NewcColor
        if(color == newColor) return image;
        dfs(sr,sc,image,color,newColor);
        return image;
    }
};