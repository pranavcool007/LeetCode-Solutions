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


/* NOTE : sum will be INT_MIN as we are comparing each level sum, if taken 0 and all level
          sums are -ves then this case will fail, INT_MIN will keep a note of it.
*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = INT_MIN;                 // max sum of a level
        int level = 1;
        int max_level;               // level no that has max sum
        while(q.size() > 0){
            int count = q.size();
            int level_sum = 0;
            for(int i=0; i<count; ++i){
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(level_sum > sum){
                sum = level_sum;
                max_level = level;
            }
            ++level;
        }
        return max_level;
    }
};