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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base cases
        if(p == NULL and q==NULL){
            return true;
        } 
        if(p == NULL or q == NULL){
            return false;
        }
        
        //check root node
        if(p->val != q->val){
            return false;
        }
        // call lst and rst
        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right,q->right);
        
        // if both subtrees are same then true otherwise false
        if(l and r){
            return true;
        }
        return false;
    }
};