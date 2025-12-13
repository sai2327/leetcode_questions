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
    bool path(TreeNode* root,int target,int sum){
        if(root==NULL) return false;
        sum+=root->val;
        if(sum==target and root->left==NULL and root->right==NULL) return true;
        bool l=false,r=false;
        if(root->left){
            l=path(root->left,target,sum);
        }
        if(root->right) r=path(root->right,target,sum);
        return l or r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return NULL;
        int sum=0;
        return path(root,targetSum,sum);
        

    }
};