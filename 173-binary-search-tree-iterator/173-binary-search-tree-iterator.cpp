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
class BSTIterator {
public:
    int i;
    vector<int> in;
    BSTIterator(TreeNode* root) {
        i = -1;
        Inorder(root,in);
    }
    void Inorder(TreeNode* root,vector<int> &in){
            if(root == NULL) return;
            Inorder(root->left,in);
            in.push_back(root->val);
            Inorder(root->right,in);
        }
    
    int next() {
        return in[++i];
    }
    
    bool hasNext() {
        if(i+1 < in.size()){
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