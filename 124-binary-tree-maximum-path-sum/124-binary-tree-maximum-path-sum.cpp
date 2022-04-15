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
    int maxPathSum(TreeNode* root) {
       int max_sum = INT_MIN;
       helper(root,max_sum);
       return max_sum; 
    }
    
    int helper(TreeNode* root,int &max_sum){
        if(root == NULL) return 0;
        
        int left = max(0,helper(root->left,max_sum));
        int right = max(0,helper(root->right,max_sum));
        
        max_sum = max(max_sum,left + right + root->val);
        
        return root->val + max(left,right);
    }
};