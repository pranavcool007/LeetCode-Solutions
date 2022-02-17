/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool direction = true;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        TreeNode* node = root;
        q.push(node);
        
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i =0; i<size; ++i)
            {
                node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(direction){
                ans.push_back(level);
            }
            else{
                reverse(level.begin(),level.end());      // stupid mistake
                ans.push_back(level);
            }
            direction = !direction;
        }
        return ans;
     
    }
};