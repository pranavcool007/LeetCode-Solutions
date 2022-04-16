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
/* For O(n) space and time complex, make a map with all the nodes val and their level, take 
    max level node val and add it.
    
    For O(n) time and only recursion space , make a var (call by ref)deepest_l that will keep
    track of deepest leaf node , node if c_level == deepest_l then update ans by adding that 
    leaf val and if c_level > deepest_l reset ans to 0 and then add the root val
*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int c_level = 0;
        int deepest_l = 0;
        int ans = 0;
        helper(root,c_level,deepest_l,ans);
        return ans;
    }
    
    void helper(TreeNode* root,int c_level,int &deepest_l,int &ans){
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL){
            if(c_level == deepest_l){
                ans += root->val;
            }
            else if(c_level > deepest_l){
                ans = 0;
                ans += root->val;
                deepest_l = c_level;
            }
        }
        helper(root->left,c_level+1,deepest_l,ans);
        helper(root->right,c_level+1,deepest_l,ans);
    }
};