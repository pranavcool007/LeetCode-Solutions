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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left_h = leftH(root->left);
        int right_h = rightH(root->right);
        
        if(left_h == right_h) return (1 << left_h + 1)-1;
        else{
            int left_n = countNodes(root->left);
            int right_n = countNodes(root->right);
            return 1 + left_n + right_n;
        }
    }
    int rightH(TreeNode* root){
        int h = 0;
        TreeNode* node = root;
        while(node){
            ++h;
            node = node->right;
        }
        return h;
    }
    int leftH(TreeNode* root){
        int h = 0;
        TreeNode* node = root;
        while(node){
            ++h;
            node = node->left;
        }
        return h;
    }
};