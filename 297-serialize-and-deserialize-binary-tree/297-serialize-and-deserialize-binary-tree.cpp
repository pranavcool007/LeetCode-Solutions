/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        ans.append(to_string(root->val));
        ans.append(",");
        while(!q.empty()){
             TreeNode* node = q.front();
             q.pop();
             if(node->left){
                 q.push(node->left);
                 ans.append(to_string(node->left->val));
                 ans.append(",");
             }else{
                 ans.append("#,");
             }
             if(node->right){
                 q.push(node->right);
                 ans.append(to_string(node->right->val));
                 ans.append(",");
             }else{
                 ans.append("#,");
             }
         }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        string str;
        queue<TreeNode*> q;
        stringstream s(data);
        getline(s,str,',');
        
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* l = new TreeNode(stoi(str));
                node->left = l;
                q.push(l);
            }
            
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* r = new TreeNode(stoi(str));
                node->right = r;
                q.push(r);
            }
        }
        return root;

}
        
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));