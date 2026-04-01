// Last updated: 01/04/2026, 19:27:23
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
    int leftfindHeight(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + leftfindHeight(root -> left);
}
    int rightfindHeight(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + rightfindHeight(root -> right);
}    
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = leftfindHeight(root);
        int r = rightfindHeight(root);
        if(l == r) return (1 << l) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};