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
/* as constraints are node val can be INT_MAX or INT_MIN we have to take larger range to get    the code to work. Also for recursion imagine one node whose val is in range then to return    true , null values must be returned with true as base case.   */
    
    bool isValidBST(TreeNode* root) {
        long min = LONG_MIN;
        long max = LONG_MAX;
        bool ans = helper(min,max,root);
        return ans;
    }
    
    bool helper(long min,long max,TreeNode* root){
        if(root == NULL) return true;
        if(root->val < max and root->val > min){
            
           bool lst = helper(min,root->val,root->left);
           bool rst = helper(root->val,max,root->right);
            return lst and rst;
        }
        else{
            return false;
        }
    }   
};