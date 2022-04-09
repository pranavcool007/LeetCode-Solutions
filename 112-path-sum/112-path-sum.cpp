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