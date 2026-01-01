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
    vector<TreeNode*> res;
    void spirit(TreeNode*& root,unordered_set<int>&st){
        if(!root) return;
        spirit(root->left,st);
        spirit(root->right,st);
        if(st.count(root->val)){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root=nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st;
        for(auto i:to_delete){
            st.insert(i);
        }
        spirit(root,st);
        if(root && !st.count(root->val))res.push_back(root);
        return res;
    }
};