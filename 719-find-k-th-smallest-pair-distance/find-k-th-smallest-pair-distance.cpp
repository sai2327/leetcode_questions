class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int cnt=0;
            int m=(l+r)/2;
            for(int i=0,j=0;i<n;i++){
                while(j<n and nums[j]<=nums[i]+m) j++;
                cnt+=j-i-1;
            }
            if(cnt<k) l=m+1;
            else r=m;
        }
        return l;
    }
};