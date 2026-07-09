class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<int>c(n,0);
        int cur=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) cur++;
            c[i]=cur;
        }
        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            if(c[queries[i][0]]==c[queries[i][1]])ans[i]=true;
        }
        return ans;
    }
};