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
    bool sametree(TreeNode* root1 , TreeNode* root2){
        if(root1 == NULL and root2 == NULL) return true;
        if(root1 == NULL or root2 == NULL) return false;
        
        if(root1->val != root2->val){
            return false;
        }
        bool l = sametree(root1->left,root2->left);
        bool r = sametree(root1->right,root2->right);
        
        if(l and r){
            return true;
        }
        return false;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        bool main = sametree(root,subRoot);
        if(main){
            return true;
        }
        return (isSubtree(root->left,subRoot) or 
            isSubtree(root->right,subRoot));
        
    }
};