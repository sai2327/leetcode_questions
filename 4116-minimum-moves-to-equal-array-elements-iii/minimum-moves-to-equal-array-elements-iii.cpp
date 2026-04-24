class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int res=0;
        for(int i:nums) res+=(maxi-i);
        return res;
    }
};