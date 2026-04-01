// Last updated: 01/04/2026, 19:27:00
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

    string serialize(TreeNode* root) {
    if(root == nullptr) return "";
    queue<TreeNode*> q;
    q.push(root);
    string s = "";
    while(!q.empty()){
        if(q.front() == nullptr){
            s += '#';
            s += ',';
            q.pop();
            continue;
        }
        TreeNode* cur = q.front();
        q.pop();
        s += to_string(cur -> val);
        s += ',';
        q.push(cur -> left);
        q.push(cur -> right);
    }
    return s;
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        stringstream ss(data);
        string taken;
        queue<TreeNode*> q;
        if(n == 0) return nullptr;
        int i = 0;
        getline(ss,taken,',');
        TreeNode* root = new TreeNode(stoi(taken));
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(getline(ss,taken,',')){
            if(taken != "#") cur -> left = new TreeNode(stoi(taken));
            else cur -> left = nullptr;
            if(cur -> left) q.push(cur -> left);
            }
            if(getline(ss,taken,',')){
            if(taken != "#")cur -> right = new TreeNode(stoi(taken));
            else cur -> right = nullptr;
            if(cur -> right) q.push(cur -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));