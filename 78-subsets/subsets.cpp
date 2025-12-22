class Solution {
public:
    vector<vector<int>>res;
    vector<int>ans;
    void dfs(vector<int>&nums,int i){
        if(i>=nums.size()) {
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        cout<<ans.back()<<" ";
        dfs(nums,i+1);
        cout<<"--"<<ans.back()<<" ";
        ans.pop_back();
        dfs(nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       dfs(nums,0); 
       return res;
    }
};