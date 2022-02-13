/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_finder(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_map) 
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                parent_map[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_map[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_map;  // pass by ref to find parents 
        parent_finder(root,parent_map);                 // of every node
    
        unordered_map<TreeNode*,int> visited;           // visited map bettr to take bool
        queue<TreeNode*> q;
        q.push(target);                  // initially put target in the q
        ++visited[target];               // make target as visited
        int dist = 0;
        
        while(!q.empty()){
            
            if(dist == k){
                break;
            }else{
                dist++;
            }
            
            int size = q.size();       // iterate for all nodes in q 
                                       // after for loop all distance = dist nodes will be                                             present in the queue
            
            for(int i = 0;i < size; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left and !visited[node->left]){
                    ++visited[node->left];
                    q.push(node->left);
                }
                if(node->right and !visited[node->right]){
                    ++visited[node->right];
                    q.push(node->right);
                }
                if(parent_map[node] and !visited[parent_map[node]]){
                    ++visited[parent_map[node]];
                    q.push(parent_map[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
        
    }
};