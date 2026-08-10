class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long s=0;
        for(int x:nums) s^=x;
        long long r=s & -s;
        int a=0,b=0;
        for(int x:nums){
            if(x&r) a^=x;
            else b^=x;
        }
        return {a,b};
    }
};