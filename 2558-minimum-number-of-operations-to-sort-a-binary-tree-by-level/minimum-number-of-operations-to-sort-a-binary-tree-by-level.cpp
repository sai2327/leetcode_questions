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
    int count(vector<int>&arr){
        vector<int>b=arr;
        sort(b.begin(),b.end());
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]=i;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=b[i]){
                ans++;
                mp[arr[i]]=mp[b[i]];
                swap(arr[i],arr[mp[b[i]]]);
            }
        }
        return ans;
    } 
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>arr;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans+=count(arr);
        }
        return ans;
    }
};