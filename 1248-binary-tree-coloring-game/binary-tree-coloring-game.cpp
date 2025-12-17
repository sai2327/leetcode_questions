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
    int leftcnt=0,rightcnt=0;
    int dfs(TreeNode* root,int x){
        if(!root) return 0;
        int left=dfs(root->left,x);
        int right=dfs(root->right,x);
        if(root->val==x){
            leftcnt=left;
            rightcnt=right;
        }
        return left+right+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root,x);
        int parent=n-leftcnt-rightcnt-1;
        int maxi=max(parent,max(leftcnt,rightcnt));
        return maxi*2>n;
    }
};