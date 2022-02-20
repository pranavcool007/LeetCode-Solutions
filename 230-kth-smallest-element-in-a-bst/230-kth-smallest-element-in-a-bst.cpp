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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        // inorder recursive
        if(root == NULL) return 0;
        
        kthSmallest(root->left,k);
        ++count;
        if(count == k){
            ans = root->val;
        }
        kthSmallest(root->right,k);
        return ans;
    }
};