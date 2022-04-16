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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        bool flag = false;
        preorder(root,sum,flag);
        return sum;
    }
    
    void preorder(TreeNode* root,int &sum,bool &flag){
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL and flag == true){
            sum += root->val;
        }
        flag = true;
        preorder(root->left,sum,flag);
        flag = false;
        preorder(root->right,sum,flag);
    }
};