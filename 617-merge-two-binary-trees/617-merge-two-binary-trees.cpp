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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 and root2){
            
        root1->val = root1->val + root2->val;
        TreeNode* l = mergeTrees(root1->left,root2->left);
        TreeNode* r = mergeTrees(root1->right,root2->right);
        root1->left = l;
        root1->right = r;
        
        return root1;
        }
        else if(root1 !=NULL or root2 !=NULL){
            return root1?root1:root2;
        }else{
            return NULL;
        }
    }
};