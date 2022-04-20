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

/* the constructor is just like a function, and it has block scope too, other functions
   cannot access the local values inside the constructor */

class BSTIterator {
public:
    int i;
    vector<int> arr;
    BSTIterator(TreeNode* root) {                           
        i = -1;
        Inorder(root,arr);
    }
    void Inorder(TreeNode* root,vector<int> &arr){
        if(root == NULL) return;
        Inorder(root->left,arr);
        arr.push_back(root->val);
        Inorder(root->right,arr);
    }
    
    int next() {
        return arr[++i];
    }
    
    bool hasNext() {
        if(i+1 < arr.size()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */