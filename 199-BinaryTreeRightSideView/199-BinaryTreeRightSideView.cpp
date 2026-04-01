// Last updated: 01/04/2026, 19:27:32
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
    vector<int> rightSideView(TreeNode* root) {
      if(root == nullptr) return {};
      queue<pair<TreeNode*,int>> q;
      map<int,int> mp;
      vector<int> ans;
      int index = 0;
      q.push({root,index});
      while(!q.empty()){
        auto it = q.front();
        index = it.second;
        mp[index] = it.first -> val;
        if(it.first -> left) q.push({it.first ->left,index + 1});
        if(it.first -> right) q.push({it.first ->right,index + 1});
        q.pop();
      }  
      for(auto& [k,v] : mp){
        ans.push_back(v);
      }
      return ans;
    }
};