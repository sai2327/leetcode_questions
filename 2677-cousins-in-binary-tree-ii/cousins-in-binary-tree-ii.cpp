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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        root->val=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(),sum=0;
            vector<TreeNode*>temp;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr);
                if(curr->left){
                    q.push(curr->left);
                    sum+=curr->left->val;
                }
                if(curr->right){
                    q.push(curr->right);
                    sum+=curr->right->val;
                }
            }
            for(auto curr:temp){
                int temp1=sum;
                if(curr->left) temp1-=curr->left->val;
                if(curr->right) temp1-=curr->right->val;
                if(curr->left) curr->left->val=temp1;
                if(curr->right) curr->right->val=temp1;
            }
        }
        return root;
    }
};