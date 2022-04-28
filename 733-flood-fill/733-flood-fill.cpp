class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int k,int newColor){
        int rows = image.size();
        int cols = image[0].size();
        if(i<0 || j<0 || i>=rows || j>= cols|| image[i][j] != k){
            return;
        }
        image[i][j] = newColor;
        dfs(i+1,j,image,k,newColor);
        dfs(i-1,j,image,k,newColor);
        dfs(i,j+1,image,k,newColor);
        dfs(i,j-1,image,k,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int colour =  image[sr][sc];
        if(colour == newColor) return image;
        dfs(sr,sc,image,colour,newColor);
        return image;
    }
};