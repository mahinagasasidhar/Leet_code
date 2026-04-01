// Last updated: 01/04/2026, 19:24:45
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
    void dfs(TreeNode* root,int start,TreeNode*& target){
        if(root == nullptr) return;
        if(root -> val == start){
            target = root;
            return;
        }
        dfs(root -> left,start,target);
        dfs(root -> right,start,target);
    }
    private:
    void parentmapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        if(root -> left) parent[root -> left] = root, parentmapping(root -> left,parent);
        if(root -> right) parent[root -> right] = root, parentmapping(root -> right,parent);
    }
    private:
    void totaltime(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,unordered_set<TreeNode*>& st,int time,int& maxtime){
        if(root == nullptr) return;
        st.insert(root);
        time++;
        if(root -> left && !st.count(root -> left)) maxtime = max(maxtime,time),totaltime(root -> left,parent,st,time,maxtime);
        if(root -> right && !st.count(root -> right)) maxtime = max(maxtime,time),totaltime(root -> right,parent,st,time,maxtime);
        if(parent.count(root) && !st.count(parent[root])) maxtime = max(maxtime,time), totaltime(parent[root],parent,st,time,maxtime);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target; 
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> st;
        int time = 0;
        int maxtime = 0;
        parentmapping(root,parent);
        dfs(root,start,target);
        totaltime(target,parent,st,time,maxtime);
        return maxtime;
    }
};