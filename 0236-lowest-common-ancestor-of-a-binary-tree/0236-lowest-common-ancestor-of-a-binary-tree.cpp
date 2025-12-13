/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q) return root;
        TreeNode* leftlca=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightlca=lowestCommonAncestor(root->right,p,q);
        if(leftlca!=NULL and rightlca!=NULL) return root;
        if(leftlca!=NULL) return leftlca;
        return rightlca;
    }
};