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
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    TreeNode* spirit(TreeNode* root,int maxi,int len){
        if(!root) return NULL;
        if(maxi-1==len) return root;
        TreeNode* left=spirit(root->left,maxi,len+1);
        TreeNode* right=spirit(root->right,maxi,len+1);
        if(left and right) return root;
        if(left) return left;
        return right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return spirit(root,maxDepth(root),0);
    }
};