// Last updated: 01/04/2026, 19:27:49
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        while(!st.empty()){
            TreeNode* dummy = st.top();
            st.pop();
            if(dummy->left != nullptr) st.push(dummy -> left);
            if(dummy->right != nullptr) st.push(dummy -> right);
            ans.push_back(dummy -> val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};