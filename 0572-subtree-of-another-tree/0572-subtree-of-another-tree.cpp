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
    bool isidentical(TreeNode* root,TreeNode* subRoot){
        if(root==NULL or subRoot==NULL) return root==subRoot;
        return root->val==subRoot->val and isidentical(root->right,subRoot->right) and isidentical(root->left,subRoot->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL or subRoot==NULL) return root==subRoot;
        if(root->val==subRoot->val and isidentical(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};