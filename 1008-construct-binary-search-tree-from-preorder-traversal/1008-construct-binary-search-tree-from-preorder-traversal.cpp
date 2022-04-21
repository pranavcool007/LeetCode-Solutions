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
        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> inmap;
        
        for(int i=0; i<inorder.size(); ++i){
            inmap[inorder[i]] = i;
        }
        TreeNode* root = treeBuilder(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inmap);
        return root;
    }
    
    TreeNode* treeBuilder(vector<int> &inorder,int instart,int inend,vector<int> &preorder,
                          int prestart,int preend,unordered_map<int,int> &inmap)
    {
        if(instart > inend || prestart > preend) return NULL;
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inRoot = inmap[preorder[prestart]];
        int left = inRoot - instart;
        
        root->left = treeBuilder(inorder,instart,inRoot-1,preorder,prestart + 1,
                                 prestart + left,inmap);
        root->right = treeBuilder(inorder,inRoot+1,inend,preorder,prestart+left+1,
                                  preend,inmap);
        return root;
    }
};