// Last updated: 01/04/2026, 19:25:51
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
    private:
    void dfs(TreeNode* root,map<int, map<int,multiset<int>>>& mp,int x,int y){
        if(root == nullptr) return;
        mp[y][x].insert(root -> val);
        dfs(root -> left,mp,x + 1,y - 1);
        dfs(root -> right,mp,x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int,multiset<int>>> mp;
    dfs(root,mp,0,0);
    vector<vector<int>> fans;
    for(auto it : mp){
        vector<int> ans;
        for(auto it2 : it.second){
            ans.insert(ans.end(),it2.second.begin(),it2.second.end());
        }
        fans.push_back(ans);
        
    }
    return fans;
    }
};