// Last updated: 01/04/2026, 19:28:19
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                ans.push_back(st.top()->val);
                node = st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};