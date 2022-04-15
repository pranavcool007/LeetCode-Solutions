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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int c_no = 0;
        helper(root,c_no,ans);
        return ans;
    }
    
    void helper(TreeNode* root,int &c_no,int &ans){
        if(root == NULL) return;
        
        c_no *= 10;
        c_no += root->val;
        if(root->left == NULL and root->right == NULL){
            ans += c_no;
            c_no = c_no/10;
            return;
        }
        
        helper(root->left,c_no,ans);
        helper(root->right,c_no,ans);
        c_no = c_no/10;
        
    }
};