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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            int prev=(level%2==0)?INT_MIN:INT_MAX;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                int v=cur->val;
                if(level%2==0){
                    if(v%2==0||v<=prev) return false;
                }else{
                    if(v%2!=0||v>=prev) return false;
                }
                prev=v;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            level++;
        }
        return true;
    }
};