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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*>st;
        for(int i=0;i<nums.size();i++){
            TreeNode* curr=new TreeNode(nums[i]);
            while(!st.empty() and st.back()->val < nums[i]){
                curr->left=st.back();
                st.pop_back();
            }
            if(!st.empty()){
                st.back()->right=curr;
            }
            st.push_back(curr);
        }
        for(int i=0;i<st.size();i++) cout<<st[i]->val<<" ";
        cout<<endl<<st.front()->val;
        return st.front();
    }
};