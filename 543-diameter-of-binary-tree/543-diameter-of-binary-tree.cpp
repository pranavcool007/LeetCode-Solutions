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
    int diam = 0;
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) return 1;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        diam = max(diam,l + r);
        
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diam;
    }
};