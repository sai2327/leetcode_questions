class Solution {
public:
    int lis(vector<int>&arr){
        vector<int>a;
        for(int i:arr){
            if(a.empty() or i>a.back()) a.push_back(i);
            else{
                auto it=lower_bound(a.begin(),a.end(),i);
                *it=i;
            }
        }
        return a.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            vector<int>arr;
            for(int j:nums){
                if((j>>i)&1) arr.push_back(j);
            }
            res=max(res,lis(arr));
        }
        return res;
    }
}; 
