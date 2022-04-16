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
    // bool can_be_palindrome(vector<int> num){
    //     unordered_map<int,int> mpp;
    //     int odd_char_count = 0;
    //     for(auto i:num){
    //         mpp[i]++;
    //     }
    //     for(auto i: mpp){
    //         int no = i.first;
    //         int freq = i.second;
    //         if(freq % 2 == 1){
    //             ++odd_char_count;
    //         }
    //     }
    //     if(odd_char_count > 1){
    //         return false;
    //     }
    //     return true;
    // }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mpp;
        int ans = 0;
        helper(root,mpp,ans);
        return ans;
    }
    
    void helper(TreeNode* root,unordered_map<int,int> mpp,int &ans){
        if(root == NULL) return;
        
        if(mpp.find(root->val) == mpp.end()){
            mpp[root->val]++;
        }else{
            if(mpp[root->val] == 1){
                mpp.erase(root->val);
            }else{
                mpp[root->val]--;
            }
        }
        
        if(root->left == NULL and root->right == NULL){
            if(mpp.size() <= 1){
                ans++;
            }
            
            return;
        }
        helper(root->left,mpp,ans);
        helper(root->right,mpp,ans);
        
    }
};