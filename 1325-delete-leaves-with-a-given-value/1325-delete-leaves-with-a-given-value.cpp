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
    
/* as we have to check for parent after checking for child nodes we will do postorder 
    traversal , after checking for children check for parent if its leaf node and val == 
    target, if yes return null else return its root.
    
*/
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;
        
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        
        if(root->right == root->left and root->val == target){
            return NULL;
        }else{
            return root;
        }
    }
};