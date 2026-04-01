// Last updated: 01/04/2026, 19:26:27

class Solution {
public:
    int dfs(TreeNode* root,int &d){
        if(root == nullptr) return 0;
        int l = dfs(root -> left,d);
        int r = dfs(root -> right,d);
        d = max(d,l+r);
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
    dfs(root,diameter);
    return diameter ;
    }
};