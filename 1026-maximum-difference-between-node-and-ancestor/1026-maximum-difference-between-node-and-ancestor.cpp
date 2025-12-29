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
    int maxdiff;
    void dfs(TreeNode* root,int minval,int maxval){
        if(!root) return;
        maxdiff=max(maxdiff,max(abs(minval-root->val),abs(maxval-root->val)));
        minval=min(root->val,minval);
        maxval=max(maxval,root->val);
        dfs(root->left,minval,maxval);
        dfs(root->right,minval,maxval);
    } 
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        dfs(root,root->val,root->val);
        return maxdiff;
    }
};