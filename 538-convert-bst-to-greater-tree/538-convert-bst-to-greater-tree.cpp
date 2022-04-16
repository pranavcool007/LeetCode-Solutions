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
/* in this problem we will do reverse inorder traversal of bst in which we do sum of all nos
   greater than root, then add the sum with the root and update sum. We keep on maintain the
   current sum of nodes travelled so far.
   
   same as inorder jismein agr left ko travel krte then root ko print krte then right mein 
   travel krte, jo kaam root pe hua voh recursively sabhi nodes pe hua.
*/   
   class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        helper(root);
        return root;
        
    }
    void helper(TreeNode* root){
        if(root == NULL) return;
        helper(root->right);
        root->val = sum + root->val;
        sum = root->val;
        helper(root->left);
    }
};