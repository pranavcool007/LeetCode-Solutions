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
    void parent_find(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() > 0){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            } 
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            } 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent_find(root,parent);
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        
        while(q.size() > 0){
            if(dist == k) break;
            else dist++;
            int count = q.size();
            for(int i=0; i<count; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left and !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                } 
                if(node->right and !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                } 
                if(parent[node] and !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                } 
                    
        }
    }
        vector<int> ans;
        while(q.size() > 0){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};