class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>e,o;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0) e.insert(nums[j]);
                else o.insert(nums[j]);
                if(o.size()==e.size()) res=max(res,j-i+1);
            }
        }
        return res;
    }
};