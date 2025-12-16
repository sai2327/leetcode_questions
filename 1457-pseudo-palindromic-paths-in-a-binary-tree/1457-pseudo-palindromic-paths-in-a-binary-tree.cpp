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
    int cnt=0;
    unordered_map<int,int>mp;
    bool ispalindrome(){
        int odd=0;
        for(auto i:mp){
            if(i.second%2==1) odd++;
        }
        return odd<=1;
    }
    void darling(TreeNode* root){
        if(root==NULL) return ;
        mp[root->val]++;
        darling(root->left);
        darling(root->right);
        if(root->left==NULL and root->right==NULL){
            if(ispalindrome()) cnt++;
        }
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        cnt=0;
        darling(root);
        return cnt;
    }
};