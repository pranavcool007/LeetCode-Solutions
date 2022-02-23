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
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int i = 0;
        TreeNode* root = buildBST(preorder,i,INT_MAX);
        return root;
    }
    
    TreeNode* buildBST(vector<int> &pl,int &i,int bound){
        
        if(i == pl.size() or pl[i] > bound) return NULL;
        
        TreeNode* root = new TreeNode(pl[i++]);
        root->left = buildBST(pl,i,root->val);
        root->right = buildBST(pl,i,bound);
        
        return root;
    }
};