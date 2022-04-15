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
    vector<string> binaryTreePaths(TreeNode* root) {
        string c_path = "";
        vector<string> ans;
        helper(root,c_path,ans);
        return ans;
    }
    
    void helper(TreeNode* root,string c_path, vector<string> &ans){
        if(root == NULL){
            return;
        }
        c_path += to_string(root->val);
        if(root->left == NULL and root->right == NULL){
            ans.push_back(c_path);
            return;
        }
    
        helper(root->left,c_path+"->",ans);
        helper(root->right,c_path+"->",ans);
    }
};