class Solution {
public:
    set<vector<int>>res;
    vector<int>ans;
    void dfs(vector<int>&nums,int i){
        if(i>=nums.size()){
            res.insert(ans);
            return;
        }
        ans.push_back(nums[i]);
        dfs(nums,i+1);
        ans.pop_back();
        dfs(nums,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {\
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        vector<vector<int>>result(res.begin(),res.end());
        return result;
    }
};