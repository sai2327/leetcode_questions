class Solution {
public:
    bool can(int n,vector<int>&quantities,int mid){
        int sum=0;
        for(auto i:quantities){
            sum+=(i+mid-1)/mid;
            if(sum >n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1,high=1e6,ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(can(n,quantities,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};