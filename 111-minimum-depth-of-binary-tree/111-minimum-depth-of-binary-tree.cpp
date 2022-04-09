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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) return 1;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        /* for test case like 
                 1
                  \
                   2
                    \
                     3
                      \
                       4
                       
          the min height logic of 1 + min(l,r) will fail , if l or r == 0 return the
          non zero value of other subtree + 1;
        */
        
        if(l == 0 or r == 0){
            if(l == 0){
                return r + 1;
            }
            if(r == 0){
                return l + 1;
            }
        }
        return 1 + min(l,r);
        
    }
};