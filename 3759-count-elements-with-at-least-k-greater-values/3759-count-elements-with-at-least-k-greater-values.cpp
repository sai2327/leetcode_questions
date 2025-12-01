class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j]){
                    cnt=nums.size()-j+1;
                    break;
                }
            }
            if(cnt>=k) ans++;
        }
        return ans;
    }
};