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
    // brute force method
    void inorder(TreeNode* root,vector<int> & inor){
        if(root == NULL){
            return;
        }
        inorder(root->left,inor);
        inor.push_back(root->val);
        inorder(root->right,inor);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inor;   // will contain sorted inorder traversal
        inorder(root,inor);
        
        int i = 0;
        int j = inor.size()-1;
        while(i<j){
            if(inor[i]+inor[j] == k){
                return true;
            }
            else if(inor[i]+inor[j] > k){
                --j;
            }
            else{
                ++i;
            }   
        }
        return false;
    }
};