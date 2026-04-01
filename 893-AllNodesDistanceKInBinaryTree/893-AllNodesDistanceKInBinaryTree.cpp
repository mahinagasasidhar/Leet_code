// Last updated: 01/04/2026, 19:26:07
class Solution {
    void parentmapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        if(root -> left) parent[root -> left] = root,parentmapping(root -> left,parent);
        if(root -> right) parent[root -> right] = root,parentmapping(root -> right,parent);
    }
    void Nodes(TreeNode* root,unordered_set<TreeNode*>& st,vector<int>& v,int k,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        st.insert(root);
        int dis = 0;
        while(!q.empty()){
            int n = q.size();
            if(dis == k) break;
            dis++;
            for(int i = 0; i < n;i++){
            if(q.front() -> left && !st.count(q.front() -> left)){
                q.push(q.front() -> left);
                st.insert(q.front() -> left);
            }
            if(q.front() -> right && !st.count(q.front() -> right)){
                q.push(q.front() -> right);
                st.insert(q.front() -> right);
            }
            if(parent.count(q.front()) && !st.count(parent[q.front()])){
                q.push(parent[q.front()]);
                st.insert(parent[q.front()]);
            }
            q.pop();
            }
        }
        while(!q.empty()) v.push_back(q.front() -> val),q.pop();
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*> parent;
       vector<int> v;
       unordered_set<TreeNode*> st;
       parentmapping(root,parent);
       Nodes(target,st,v,k,parent);
       return v;
    }
};