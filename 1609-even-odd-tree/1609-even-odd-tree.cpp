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
            
            for(int i=0; i<count; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(level_no % 2 == node->val % 2){
                    return false;
                }
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level_no % 2 == 0){
                for(int i=0; i<count-1; ++i){
                    if(level[i+1] <= level[i]){
                        return false;
                    }
                }
            }
            else {
                for(int i=0; i<count-1; ++i){
                    if(level[i+1] >= level[i]){
                        return false;
                    }
                }
            }
            
        }
        return true;
    }
};