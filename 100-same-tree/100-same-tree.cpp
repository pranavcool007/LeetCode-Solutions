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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // preorder traversal with checking each node
        
        if(p == NULL or q == NULL){
            return (p==q);
        }
        if(p->val != q->val){
            return false;
        }
        bool lh = isSameTree(p->left,q->left);
        bool rh = isSameTree(p->right,q->right);
        
        return (lh and rh);
    }
};