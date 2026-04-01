// Last updated: 01/04/2026, 19:28:12
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
       queue<TreeNode*> q;
       vector<vector<int>> fans;
       q.push(root);
       bool flag = true;
       while(!q.empty()){
       int n = q.size();
       vector<int> ans(n);
       for(int i = 0;i < n;i++){
        if(q.front() -> left != nullptr)q.push(q.front()->left);
        if(q.front() -> right != nullptr)q.push(q.front()->right);
        int idx = (flag == true) ? i : n-i-1;
        ans[idx] = q.front()->val;
        q.pop();
       }
       fans.push_back(ans);
       flag = !flag;
       }
       return fans;
    }
};