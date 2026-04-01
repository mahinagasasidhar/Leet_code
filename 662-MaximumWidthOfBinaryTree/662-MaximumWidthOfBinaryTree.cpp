// Last updated: 01/04/2026, 19:26:24
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        long long ans = 0;
        q.push({root,1});
        while(!q.empty()){
            int n = q.size();
            long long first,second;
            int mn = q.front().second;
            for(int i = 0; i < n; i++){
                auto cur = q.front();
                q.pop();
                if(i == 0) first = cur.second - mn;
                if(i == n - 1) second = cur.second - mn;
                if(cur.first -> left) q.push({cur.first -> left,2*(cur.second - mn)});
                if(cur.first -> right) q.push({cur.first -> right,2*(cur.second - mn) + 1});
            }
            ans = max(ans,second - first + 1);
        }
        return ans;
    }
};