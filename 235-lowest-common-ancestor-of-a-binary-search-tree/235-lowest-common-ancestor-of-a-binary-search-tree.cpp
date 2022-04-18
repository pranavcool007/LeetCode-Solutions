/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
/* 3 cases:
            1. root has val of either of p or q
            2. both values are lesser than root
            3. both values are greater than root
*/

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val or root->val == q->val){
            return root;
        }
        if(p->val < root->val and q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(p->val > root->val and q->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};