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
    void inorder_tr(TreeNode* root,vector<int> &inorder){
        if(root == NULL) return;
        inorder_tr(root->left,inorder);
        inorder.push_back(root->val);
        inorder_tr(root->right,inorder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorder_tr(root,inorder);
        
        for(int i=0; i<inorder.size()-1; ++i){
            if(inorder[i]>=inorder[i+1]){
                return false;
            }
        }
        return true;
    }
};