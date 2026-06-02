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
    TreeNode* lca(TreeNode* root,int start,int dest){
        if(!root or root->val==start or root->val==dest) return root;
        TreeNode* left=lca(root->left,start,dest);
        TreeNode* right=lca(root->right,start,dest);
        if(left and right) return root;
        if(left) return left;
        return right;
    }
    bool path(TreeNode* root,string &s,int target){
        if(!root) return false;
        if(root->val==target) return true;
        s.push_back('L');
        if(path(root->left,s,target)) return true;
        s.pop_back();
        s.push_back('R');
        if(path(root->right,s,target)) return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int start, int dest) {
        TreeNode* node=lca(root,start,dest);
        string s="",d="";
        path(node,s,start);
        path(node,d,dest);
        string res=string(s.size(),'U');
        return res+d;
    }
};