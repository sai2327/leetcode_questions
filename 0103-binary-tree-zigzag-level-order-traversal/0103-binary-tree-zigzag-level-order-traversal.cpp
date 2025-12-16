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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag=true;
        queue<TreeNode*>q;
        vector<vector<int>>res;
        if(!root) return res;
        res.push_back({root->val});
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                if(node->left){
                    q.push(node->left);
                    ans.push_back(node->left->val);
                }
                if(node->right){ 
                    q.push(node->right);
                    ans.push_back(node->right->val);
                }
                q.pop();
            }
            if(!flag){
                if(ans.size()!=0)res.push_back(ans);
                flag=true;
            }
            else{
                reverse(ans.begin(),ans.end());
                if(ans.size()!=0)res.push_back(ans);
                flag=false;
            }
        }
        return res;
    }
};