class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n),sorted;
        for(int i=n-1;i>=0;i--){
            int idx=lower_bound(sorted.begin(),sorted.end(),nums[i])-sorted.begin();
            res[i]=idx;
            sorted.insert(sorted.begin()+idx,nums[i]);
        }
        return res;
    }
};