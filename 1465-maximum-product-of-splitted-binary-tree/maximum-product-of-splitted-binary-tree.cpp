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
public:
    long long ans=LLONG_MIN,total=0;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int sum=root->val+dfs(root->left)+dfs(root->right);
        ans=max(ans,(total-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int mod=1e9+7;
        total=dfs(root);
        dfs(root);
        return ans%mod;
    }
};