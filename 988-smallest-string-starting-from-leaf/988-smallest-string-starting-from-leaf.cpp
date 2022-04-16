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
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string c_ans = "";
        helper(root,c_ans,ans);
        return ans;
    }
    
    void helper(TreeNode* root, string c_ans,string &ans){
        if(root == NULL) return;
        
        c_ans = char((root->val + 'a') + 0) + c_ans ;
        cout<<c_ans<<" ";
        if(root->left == NULL and root->right == NULL){
            if(c_ans < ans or ans.size() == 0){
                ans = c_ans;
            }
            return;
        }
        helper(root->left,c_ans,ans);
        helper(root->right,c_ans,ans);

    }
};