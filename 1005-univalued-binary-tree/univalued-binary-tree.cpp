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
    bool isUnivalTree(TreeNode* root,int val=-1) {
        if(!root) return true;
        if(val==-1) val=root->val;
        if(root->val!=val) return false;
        return val==root->val and isUnivalTree(root->left,val) and isUnivalTree(root->right,val);
    }
};