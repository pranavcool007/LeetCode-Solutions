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
    int deepestLeavesSum(TreeNode* root) {
        int c_level = 0;
        int deepest_l = 0;
        int ans = 0;
        helper(root,c_level,deepest_l,ans);
        return ans;
    }
    
    void helper(TreeNode* root,int c_level,int &deepest_l,int &ans){
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL){
            if(c_level == deepest_l){
                ans += root->val;
            }
            else if(c_level > deepest_l){
                ans = 0;
                ans += root->val;
                deepest_l = c_level;
            }
        }
        helper(root->left,c_level+1,deepest_l,ans);
        helper(root->right,c_level+1,deepest_l,ans);
    }
};