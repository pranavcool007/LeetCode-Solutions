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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int sum,int target_sum,vector<int> ls){
        if(root == NULL) return ;
        
        sum += root->val;
        ls.push_back(root->val);
        if(root->left == NULL and root->right == NULL){
            if(sum == target_sum){
                ans.push_back(ls);
                return;
            }
            else{
    
                return;
            }
        }
        dfs(root->left,sum,target_sum,ls);
        dfs(root->right,sum,target_sum,ls);
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum,{});
        return ans;
    }
};