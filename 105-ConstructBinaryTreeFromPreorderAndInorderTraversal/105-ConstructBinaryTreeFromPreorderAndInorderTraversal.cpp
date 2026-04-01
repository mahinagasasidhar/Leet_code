// Last updated: 01/04/2026, 19:28:09
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
    int p = 0;
    unordered_map<int,int> mp;
    private:
    TreeNode* buildtree(vector<int>& preorder,int start,int end){
        if(start > end) return nullptr;
        TreeNode* root = new TreeNode(preorder[p]);
        int pivot = mp[preorder[p]];
        p++;
        root -> left = buildtree(preorder,start,pivot - 1);
        root -> right = buildtree(preorder,pivot + 1,end);
        return root;
    }
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size();i++){
            mp[inorder[i]] = i;
        } 
        TreeNode* root = buildtree(preorder,0,inorder.size() - 1);
        return root;
    }
};