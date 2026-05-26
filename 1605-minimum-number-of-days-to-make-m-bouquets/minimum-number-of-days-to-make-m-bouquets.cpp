class Solution {
public:
    bool can(vector<int>&nums ,int m,int k,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            while(i<nums.size() && cnt<k && nums[i]<=mid){
                cnt++;
                i++;
            }
            if(cnt==k){
                sum++;
                i--;
            }
            if(sum>=m)return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int low=1,high=1e9;
        while(low<high){
            int mid=(low+high)/2;
            if(can(bloomDay,m,k,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};