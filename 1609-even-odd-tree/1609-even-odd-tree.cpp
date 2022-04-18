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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level_no = -1;
        
        while(q.size() > 0){
            int count = q.size();
            ++level_no;
            vector<int> level;
            int prev = level_no % 2 ? INT_MAX : INT_MIN;
            
            for(int i=0; i<count; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                if(level_no % 2 == 0){
                    if(node->val % 2 == 0 or node->val <= prev){
                        return false;
                    }
                } else {
                    if(node->val % 2 or node->val >= prev){
                        return false;
                    }
                }
                prev = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            
        }
        return true;
    }
};