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
    void flatten(TreeNode* root) {
        // stack approach
        stack<TreeNode*> s;
        if(root == NULL) return;        // imp condition (failed 1st time)
        s.push(root);
        while(!s.empty()){

            TreeNode* node = s.top();
            s.pop();
            
            if(node->right){
                s.push(node->right);
            }
            if(node->left){
                s.push(node->left);
            }
            if(!s.empty()){
                node->right = s.top();
            }
            node->left = NULL;
        }
    }
};