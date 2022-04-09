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

/* we will do inorder traversal and keep adding the currnode val and call left and right
   subtree, if we have reached the leaf node then check sum == targetsum , also every call
   we keep on saving the sum till the current node except leaf node.
*/

class Solution {
public:
    bool dfs(TreeNode* root,int sum,int target_sum){
        if(root == NULL) return false;
        
        sum += root->val;
        if(root->left == NULL and root->right == NULL){
            return sum == target_sum;
        }
        bool l = dfs(root->left,sum,target_sum);
        bool r = dfs(root->right,sum,target_sum);
        
        return (l or r);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = dfs(root,0,targetSum);
        return ans;
    }
};