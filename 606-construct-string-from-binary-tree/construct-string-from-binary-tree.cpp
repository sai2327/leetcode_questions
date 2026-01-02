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
    string res="";
    void spirit(TreeNode* root){
        if(!root)return;
        res+=to_string(root->val);
        if(root->left){
            res+='(';
            spirit(root->left);
            res+=')';
        }
        else if(root->right) res+="()";
        if(root->right){
            res+='(';
            spirit(root->right);
            res+=')';
        }
    }
    string tree2str(TreeNode* root) {
        spirit(root);
        return res;
    }
};