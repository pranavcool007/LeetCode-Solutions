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
    int treeDepth(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) return 1;
        
        int l = treeDepth(root->left);
        int r = treeDepth(root->right);
        
        if(abs(l-r) > 1) {
            return -1;
        }
        
        if(l == -1 or r == -1){
            return -1;
        }
        else{
            return 1 + max(l,r);
        }
        
    }
    bool isBalanced(TreeNode* root) {
        int val = treeDepth(root);
        if(val == -1){
            return false;
        }
        else{
            return true;
        }
    }
};