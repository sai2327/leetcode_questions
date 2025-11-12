class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(auto i:nums){
            if(i==1)c++;
        }
        if(c==nums.size())return 0;
        int g=nums[0];
        for(int i=1;i<nums.size();i++){
            g=__gcd(nums[i],g);
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }
        }
        if(cnt>0){
            return nums.size()-cnt;
        }
        int n=nums.size();
       int mini=INT_MAX;
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                int g=nums[i];
                int cnt=0;
             for(int k=i;k<=j;k++){
                cnt++;
             g=__gcd(nums[k],g);
             }
             if(g==1)mini=min(mini,cnt);
            }
        }
        if(mini==INT_MAX)return -1;
        return mini+(n-cnt)-2;
    }
};