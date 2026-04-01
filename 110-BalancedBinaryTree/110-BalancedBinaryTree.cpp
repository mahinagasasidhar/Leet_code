// Last updated: 01/04/2026, 19:28:05
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
        int maxdepth(TreeNode* root) {
        if(root == nullptr) return 0; 
        int l = maxdepth(root -> left);
        int r = maxdepth(root -> right);
        return 1 + max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int l = maxdepth(root -> left);
        int r = maxdepth(root -> right);
        if(abs(r - l) > 1) return false;
        return(isBalanced(root -> left) && isBalanced(root -> right));
    }
};