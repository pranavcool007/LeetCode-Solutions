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
        // base cases
        if(root1 == NULL and root2 == NULL) return NULL;
        
        if(root1 != NULL and root2 == NULL){
            return root1;
        }
        else if(root2 != NULL and root1 == NULL){
            return root2;
        }
        
        // make a new node and recursively call for lst and rst
        int val = root2->val + root1->val;
        TreeNode* node = new TreeNode(val);
        
        node->left = mergeTrees(root1->left,root2->left);
        node->right = mergeTrees(root1->right,root2->right);
        
        return node;
    }
};