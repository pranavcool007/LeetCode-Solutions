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
    TreeNode* lca(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root->val == p->val or root->val == q->val){
            return root;
        }
        TreeNode* l = lca(root->left,p,q);
        TreeNode* r = lca(root->right,p,q);
        if(l != NULL and r != NULL){
            return root;
        }
        if(l != NULL or r != NULL){
            return l != NULL?l:r;
        }
        return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root or (!root->left and !root->right)) return root;
        TreeNode* leftmost = NULL;
        TreeNode* rightmost = NULL;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() > 0){
            int count = q.size();
            for(int i=0; i<count; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(i == 0) leftmost = node;
                if(i == count - 1) rightmost = node;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return lca(root,leftmost,rightmost);
    }
};