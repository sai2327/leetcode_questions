class Solution{
public:
    int countValidSelections(vector<int>& nums) {
        int cnt=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int lsum=0;
        for(int i=0;i<nums.size();i++){
            lsum+=nums[i];
            if(nums[i]==0){
                if(abs(lsum-(sum-lsum))==1) cnt++;
                else if(lsum-sum+lsum==0) cnt+=2; 
            }
        }
        return cnt;
    }
};