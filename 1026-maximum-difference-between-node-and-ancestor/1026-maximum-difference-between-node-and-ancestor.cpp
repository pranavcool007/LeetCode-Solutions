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
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        helper(root);
        return ans;
    }
    
    pair<int,int> helper(TreeNode* root){
        if(root == NULL) return {INT_MAX,INT_MIN};
        
        auto [leftmin,leftmax] = helper(root->left);
        auto [rightmin,rightmax] = helper(root->right);
        
        int cur_min = min({root->val,leftmin,rightmin});
        int cur_max = max({root->val,rightmax,leftmax});
        ans = max({ans,root->val - cur_min, cur_max - root->val});
        return {cur_min,cur_max};
    }
};