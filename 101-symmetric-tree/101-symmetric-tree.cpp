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
    bool isSymmetric(TreeNode* root) {
        bool ans = helper(root->left,root->right);
        return ans;
    }
    
    bool helper(TreeNode* l,TreeNode* r){
        if(l == NULL and r == NULL){
            return true;
        }
        if(l == NULL or r == NULL){
            return false;
        }
        if(l->val != r->val){
            return false;
        }
        bool lst = helper(l->left,r->right);
        bool rst = helper(l->right,r->left);
        return lst and rst;
    }
};