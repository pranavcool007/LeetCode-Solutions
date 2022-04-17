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
    TreeNode* prev = NULL;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* node = root;
        TreeNode* temp;
        while(node->left){
            temp = node->left;
            node = node->left;
        }
        helper(root);
        return temp;
    }
    
    void helper(TreeNode* root){
        if(root == NULL) return;
        
        helper(root->right);
        root->right = prev;
        prev = root;
        helper(root->left);
        root->left = NULL;
        
    }
};