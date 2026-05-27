class Solution {
public:
    vector<vector<int>>res;
    void rec(int i,int n,int k,vector<int>&ans){
        if(i<n and ans.size()>k) return;
        if(i > n){
            if(ans.size()==k){
                res.push_back(ans);
            }
            return;
        }
        rec(i+1,n,k,ans);
        ans.push_back(i);
        rec(i+1,n,k,ans);
        ans.pop_back();
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        rec(1,n,k,ans);
        return res;
    }
};