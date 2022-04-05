class Solution {
public:
    vector<int> ans;
    void dfs(int i, int n){
        if(i > n) return;   // jb no given range se bada ho jaye us no se return kr jayo
        
        ans.push_back(i);
        for(int j=0 ; j<=9; ++j){
            dfs(10*i + j,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1 ; i<=9; ++i){
            dfs(i,n);
        }
        return ans;
    }
};