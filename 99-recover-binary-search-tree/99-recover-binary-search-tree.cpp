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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        
        if(prev!=NULL and root->val < prev->val){
            
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev,first,middle,last = NULL;
        
        if(root == NULL) return;
        inorder(root);
        if(first and last){
            swap(first->val,last->val);
        }
        else if(first and middle){
            swap(first->val,middle->val);
        }
    }
};