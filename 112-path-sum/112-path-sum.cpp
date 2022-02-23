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
    stack<TreeNode*> s;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){  
            return false;
        }
        else if(root->left == NULL and root->right == NULL and targetSum - root->val == 0){
            return true;
        }
        else{
            bool l = hasPathSum(root->left,targetSum-root->val);
            bool r = hasPathSum(root->right,targetSum-root->val);
            return l or r;
        }
    }
};