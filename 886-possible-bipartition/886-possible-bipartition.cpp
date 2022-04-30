/* in this ques also there may be chances of disconnected graph so we have to run bfs over 
    every node
*/
class Solution {
public:
    bool checkBipartite(int cur,int n, vector<vector<int>>& dislikes,vector<int> &color,
                        vector<int> adj[]){
        
        queue<int> q;
        q.push(cur);
        color[cur] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neig : adj[node]){
                if(color[neig] == -1){
                    color[neig] = 1 - color[node];
                    q.push(neig);
                }
                else if(color[neig] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        vector<int> color(n+1,-1);
        
        // making adj graph from the dislike matrix also it will be directed according to 
        // statement
        
        for(auto i: dislikes)
        {
            int first = i[0];
            int second = i[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        for(int i=1; i<=n; ++i)
        {
            if(color[i] == -1){              // if i is not colored
                if(!checkBipartite(i,n,dislikes,color,adj)){
                    return false;
                }
            }            
        }
        return true;                         // whole graph is getting colored with no issue
    }
};