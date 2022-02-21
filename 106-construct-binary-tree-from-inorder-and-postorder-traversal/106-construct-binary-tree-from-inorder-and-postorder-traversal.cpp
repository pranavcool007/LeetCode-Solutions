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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        
        for(int i=0; i<inorder.size(); ++i){
            inmap[inorder[i]] = i;
        }
        
        TreeNode* root = buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);
        
        return root;
    }
    
    TreeNode* buildtree(vector<int>& postorder,int post_start,int post_end,vector<int>&         inorder,int in_start,int in_end,unordered_map<int,int> &inmap){
        
        if(post_start > post_end or in_start > in_end) return NULL;
        
        TreeNode* root = new TreeNode(postorder[post_end]);
        
        int inRoot = inmap[root->val];
        int numsleft = inRoot-in_start;
        
        root->left = buildtree(postorder,post_start,post_start+numsleft-1,inorder,in_start,inRoot-1,inmap);
        
        root->right = buildtree(postorder,post_start+numsleft,post_end-1,inorder,inRoot+1,in_end,inmap);
        
        return root;
    }
};