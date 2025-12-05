class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(true){
            bool flag=true;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    flag=false;
                    break;
                }
            }
            if(flag) break;
            long long min_sum=LLONG_MAX;
            int i1=0;
            for(int i=0;i<nums.size()-1;i++){
                long long sum=(long long)nums[i]+nums[i+1];
                if(sum<min_sum){
                    min_sum=sum;
                    i1=i;
                }
            }
            int a=nums[i1]+nums[i1+1];
            nums.erase(nums.begin()+i1);
            nums.erase(nums.begin()+i1);
            nums.insert(nums.begin()+i1,a);
            cnt++;
        }
        return cnt;
    }
};