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
    /* just swap the left leftsubtree with right and vise versa for main tree and repeat 
    recursively for left subtree and right subtree 
    */
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;
        
        invertTree(root->right);
        invertTree(root->left);
        
        return root;
    }
};