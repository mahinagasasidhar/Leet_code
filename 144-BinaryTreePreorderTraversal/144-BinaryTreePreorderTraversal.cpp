// Last updated: 01/04/2026, 19:27:50
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>ans;
       if(root==nullptr){
         return ans;
    }
     stack<TreeNode*>st;
     st.push(root);
     while(!st.empty()){
       TreeNode* node = st.top();
       ans.push_back(node->val);
       st.pop();
       if(node->right!=nullptr) st.push(node->right);
       if(node->left!=nullptr) st.push(node->left);
     }
     return ans;
    }
};