// Last updated: 01/04/2026, 19:28:07
class Solution {
    int p;
    unordered_map<int,int> mp;
    private:
    TreeNode* buildtree(vector<int>& postorder,int start,int end){
        if(start > end) return nullptr;
        const int n = postorder.size();
        TreeNode* root = new TreeNode(postorder[p]);
        int pivot = mp[postorder[p]];
        p--;
        root -> right = buildtree(postorder,pivot + 1,end);
        root -> left = buildtree(postorder,start,pivot - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        p = n - 1;
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        TreeNode* root = buildtree(postorder,0,n - 1);
        return root;
    }
};