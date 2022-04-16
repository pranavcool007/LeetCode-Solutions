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
    int sumRootToLeaf(TreeNode* root) {
        int c_sum = 0;
        int ans = 0;
        helper(root,c_sum,ans);
        return ans;
    }
    
    void helper(TreeNode* root,int c_sum,int &ans){
        if(root == NULL) return ;
        
        c_sum = c_sum*2 + root->val;
        if(root->left == NULL and root->right == NULL){
            ans += c_sum;
            return;
        }
        helper(root->left,c_sum,ans);
        helper(root->right,c_sum,ans);
    }
};