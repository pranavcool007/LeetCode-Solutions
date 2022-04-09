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
    int count = 0;
    void dfs(TreeNode* root, long curr_sum,int target_sum){
        if(root == NULL) return;
        
        curr_sum += root->val;
        if(curr_sum == target_sum){
            count++;
        }
        
        dfs(root->left,curr_sum,target_sum);
        dfs(root->right,curr_sum,target_sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        dfs(root,0,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};