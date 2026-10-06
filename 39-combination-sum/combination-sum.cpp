class Solution {
public:
    set<vector<int>>res;
    void rec(int i,int sum,vector<int>&candidates,int target,vector<int>&temp){
        if(i==candidates.size()){
            if(sum==target)res.insert(temp);
            return;
        }
        if(sum>target)return;
        temp.push_back(candidates[i]);
        sum+=candidates[i];
        rec(i,sum,candidates,target,temp);
        rec(i+1,sum,candidates,target,temp);
        sum-=candidates[i];
        temp.pop_back();
        rec(i+1,sum,candidates,target,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        rec(0,0,candidates,target,temp);
        vector<vector<int>>ans;
        for(auto i:res)ans.push_back(i);
        return ans;
    }
};