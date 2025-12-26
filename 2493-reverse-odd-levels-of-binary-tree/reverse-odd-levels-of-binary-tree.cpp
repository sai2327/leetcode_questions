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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>arr;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                arr.push_back(curr);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(flag){
                for(int i=0;i<n/2;i++){
                    swap(arr[i]->val,arr[n-1-i]->val);
                }
            }
            flag=!flag;
        }
        return root;
    }
};