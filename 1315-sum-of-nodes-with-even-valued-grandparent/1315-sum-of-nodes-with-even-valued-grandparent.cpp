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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        helper(root);
    return sum;
    }
    void helper(TreeNode* root){
        if(root == NULL) return;
        
// check wether root can be a grandparent if yes then add its grandparents(if existed) values
//   to the sum 
        if(root->val % 2 == 0){
            if(root->left and root->left->left){
                sum += root->left->left->val;
            }
            if(root->left and root->left->right){
                sum += root->left->right->val;
            }
            if(root->right and root->right->right){
                sum += root->right->right->val;
            }
            if(root->right and root->right->left){
                sum += root->right->left->val;
            }
            
        }
        helper(root->left);
        helper(root->right);
    }
};