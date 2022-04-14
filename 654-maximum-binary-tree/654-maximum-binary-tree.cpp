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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
    
        TreeNode* node = helper(0,nums.size()-1,nums);
        return node;
    }
    
    TreeNode* helper(int start,int end,vector<int>& nums){
        if(start > end){
            return NULL;
        }
        
        int idx_max = start;
        for(int i=start; i<=end; ++i){
            if(nums[idx_max] < nums[i]){
                idx_max = i;
            }
        }
        
        TreeNode* node = new TreeNode(nums[idx_max]);
        node-> left = helper(start,idx_max-1,nums);
        node->right = helper(idx_max+1,end,nums);
        
        return node;
    }
};