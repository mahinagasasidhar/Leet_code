// Last updated: 01/04/2026, 19:28:00

class Solution {
public:
    int dfs(TreeNode* root,int &maxx){
        if(root == nullptr) return 0;
        int l = max(dfs(root -> left,maxx),0);
        int r = max(dfs(root -> right,maxx),0);
        maxx = max(maxx,root -> val + l + r);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxx = INT_MIN;
        dfs(root,maxx);
        return maxx; 
    }
};