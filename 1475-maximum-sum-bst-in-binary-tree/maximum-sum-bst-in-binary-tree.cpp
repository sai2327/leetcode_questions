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
    int res=0;
    vector<int> spirit(TreeNode* root){
        if(!root) return {1,INT_MAX,INT_MIN,0}; //isbst,min,max,sum
        auto l=spirit(root->left);
        auto r=spirit(root->right);
        if(l[0] and r[0] and root->val>l[2] and root->val<r[1]){
            int sum=l[3]+r[3]+root->val;
            res=max(res,sum);
            return {1,min(root->val,l[1]),max(root->val,r[2]),sum};
        }
        return {0,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        spirit(root);
        return res;
    }
};