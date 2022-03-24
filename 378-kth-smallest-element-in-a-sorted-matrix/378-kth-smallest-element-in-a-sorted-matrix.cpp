class Solution {
public:
    bool enough(int num,vector<vector<int>>& matrix,int k ){
        int n = matrix.size();
        int total = 0;                         // vslues >= num
        int row = 0;
        int col = n-1;
        while(row < n and col >= 0){
            if(matrix[row][col] <= num){
                total += col+1;
                ++row;
            }else{
                --col;
            }
        }
        return total >= k;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n-1][n-1];
        while(start <= end){
            int mid = start + (end-start)/2;
            if(enough(mid,matrix,k)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};