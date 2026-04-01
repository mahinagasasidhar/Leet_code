// Last updated: 01/04/2026, 19:27:09
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
    bool isleaf(TreeNode* root){
        return root && !root -> left && !root -> right; 
    }
    void dfs(TreeNode* root,vector<string>& ans,string s){
        s += to_string(root -> val);
        if(isleaf(root)){
            ans.push_back(s);
            s.pop_back();
            return;
        }
        s += "->";
        if(root -> left) dfs(root -> left,ans,s);
        if(root -> right) dfs(root -> right,ans,s);
        s.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        dfs(root,ans,s);
        return ans;
    }
};