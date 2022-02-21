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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        
        for(int i=0; i<inorder.size(); ++i){
            inmap[inorder[i]] = i;
        }
        
        TreeNode* root = buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        
        return root;
    }
    
    TreeNode* buildtree(vector<int>& preorder,int pre_start,int pre_end,vector<int>&         inorder,int in_start,int in_end,unordered_map<int,int> &inmap){
        
        if(pre_start > pre_end or in_start > in_end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        int inRoot = inmap[root->val];
        int numsleft = inRoot-in_start;
        
        root->left = buildtree(preorder,pre_start+1,pre_start+numsleft,inorder,in_start,inRoot-1,inmap);
        
        root->right = buildtree(preorder,pre_start+numsleft+1,pre_end,inorder,inRoot+1,in_end,inmap);
        
        return root;
    }
};