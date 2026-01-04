class Solution {
public:
    int res=0;
    void arefactors(int n){
        int sum=0,cnt=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i!=n/i){
                    sum+=i;
                    sum+=n/i;
                    cnt+=2;
                }
                else{
                    sum+=i;
                    cnt++;
                }
                if(cnt>4) return ;
            }
        }
        if(cnt==4){
            res+=sum;
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            arefactors(nums[i]);
        }
        return res;
    }
};