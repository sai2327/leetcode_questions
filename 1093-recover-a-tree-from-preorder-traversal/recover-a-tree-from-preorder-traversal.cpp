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
    TreeNode* recoverFromPreorder(string s) {
        vector<TreeNode*>st;
        for(int i=0;i<s.size();){
            int level=0,val=0;
            for(i;s[i]=='-';i++) level++;
            for(i;i<s.size() and s[i]!='-';i++) val=val*10+(s[i]-'0');
            TreeNode* node= new TreeNode(val);
            while(st.size()>level) st.pop_back();
            if(!st.empty()){
                if(!st.back()->left) st.back()->left=node;
                else st.back()->right=node;
            }
            st.push_back(node);
        }
        return st[0];
    }
};