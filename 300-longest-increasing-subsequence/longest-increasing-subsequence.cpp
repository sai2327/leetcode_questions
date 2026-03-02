class Solution {
public:
    int binarysearch(vector<int>&res,int target){
        int low=0,high=res.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(res[mid]==target) return mid;
            else if(res[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(int i:nums){
            if(res.empty() or res.back()<i) res.push_back(i);
            else {
                int idx=binarysearch(res,i);
                res[idx]=i;
            }
        }
        return res.size();
    }
};