class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long ,int>mp;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int res=0;
        for(auto i:mp){
            res+=8*(i.second*(i.second-1))/2;
        }
        return res;
    }
};