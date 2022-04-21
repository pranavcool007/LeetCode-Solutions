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
    void buildString(TreeNode* root, string &s){
        if(root == NULL){
            s += "x,";
            return;
        }
        s += to_string(root->val) + ",";
        buildString(root->left,s);
        buildString(root->right,s);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s = "";
        buildString(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        queue<string> q;
        string temp = "";
        for(char ch : data){
            if(ch == ','){
                q.push(temp);
                temp = "";
            }else{
                temp += ch;                 // temp = ch is error
            }
        }
        TreeNode* root = helper_deserialize(q);
        return root;
    }
    
    TreeNode* helper_deserialize(queue<string> &q){
        string s = q.front();
        q.pop();
                
        if(s == "x") return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = helper_deserialize(q);
        root->right = helper_deserialize(q);
            
        return root;
    }
 
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));