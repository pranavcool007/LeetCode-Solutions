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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else{           // key found    
            
            // 0 child
            if(root->left == NULL and root->right == NULL){
                delete root;
                root = NULL;
                return root;
            }
            // 1 child
            else if(root->left == NULL or root->right == NULL){
                TreeNode* temp = root->right?root->right:root->left;
                delete root;
                return temp;
            }
            // else if(root->right == NULL){
            //     TreeNode* temp = root->left;
            //     delete root;
            //     return temp;
            // }
            // 2 children
            else{
                TreeNode* temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
                return root;
            }
        }
        return root;
    }
};