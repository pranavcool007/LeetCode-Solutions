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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;                     // no nodes = 0 width
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(q.size() > 0){
            int count = q.size();
            int first,last;
            int min_idx = q.front().second;
            
            for(int i=0; i< count; ++i){
                TreeNode* node = q.front().first;
                int idx = q.front().second - min_idx;
                q.pop();
            
                if(node->left){
                    q.push({node->left,(long)idx*2+1});
                }
                if(node->right){
                    q.push({node->right,(long)idx*2+2});
                }
                if(i == 0){                            // first node in the level
                    first = idx;
                }
                if(i == count-1){                  // last node in the level
                    last = idx;
                }
                
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
    
};