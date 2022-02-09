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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int level = it.second;
            
            if(mpp.find(level) == mpp.end()){
                mpp[level] = node->val;
            }
            
            if(node->right){
                q.push({node->right,level+1});
            }
            if(node->left){
                q.push({node->left,level+1});
            }
        }
        for(auto temp: mpp){
            ans.push_back(temp.second);
        }
        return ans;
        
    }
};