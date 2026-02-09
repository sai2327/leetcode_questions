class Solution {
public:
    int cnt=0;
    void merge(int low,int mid , int high , vector<int>&nums){
        vector<int> temp;
        int l = low;
        int m = mid+1;
        while(l<=mid && m<=high){
            if(nums[l]<=nums[m]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[m]);
                m++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(m<=high){
            temp.push_back(nums[m]);
            m++;
        }
        int i=low;
        for(auto it:temp){
            nums[i] = it;
            i++;
        }
    }
    void countpairs(int low ,int mid,int high,vector<int>&nums){
        int r=mid+1;
        for(int i=low;i<=mid;i++){
            while(r<=high and (long long)nums[i]>2LL*nums[r]) r++;
            cnt+=(r-mid-1);
        }
    }
    void mergesort(int low,int high,vector<int>&nums){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);
        countpairs(low,mid,high,nums);
        merge(low ,mid ,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(0,n-1,nums);
        return cnt;
    }
};