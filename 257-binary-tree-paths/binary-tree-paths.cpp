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
    vector<string>res;
    void dfs(TreeNode* root,string path,vector<string>&res){
        if(root->left==NULL and  root->right==NULL){
            res.push_back(path);
            return;
        }
        if(root->left) dfs(root->left,path+"->"+to_string(root->left->val),res);
        if(root->right) dfs(root->right,path+"->"+to_string(root->right->val),res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,to_string(root->val),res);
        return res;
    }
};