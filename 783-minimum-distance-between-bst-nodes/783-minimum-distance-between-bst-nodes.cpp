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

/* as its bst go through the inorder and keep taking the diff of curr and prev nodes, the min 
   value of all these diff will be ans
*/

class Solution {
public:
    int ans = INT_MAX;
    TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        
        minDiffInBST(root->left);
        
        if(prev != NULL){
            ans = min(ans,root->val - prev->val);
        }
        prev = root;
        
        minDiffInBST(root->right);
        return ans;
    }
    
};