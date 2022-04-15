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
    unordered_map<int,int> mpp;
    // similar to 2-sum method here just put in unordered map without index
    bool findTarget(TreeNode* root, int k) {
        
        if(root == NULL) return false;
        if(mpp.find(k - root->val) != mpp.end()) return true;
        mpp[root->val]++;
        bool l = findTarget(root->left,k);
        bool r = findTarget(root->right,k);
        return l or r;
    }
};