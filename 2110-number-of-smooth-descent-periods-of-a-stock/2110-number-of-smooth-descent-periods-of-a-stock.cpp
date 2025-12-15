class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt=1, res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1) cnt++;
            else{
                res+=cnt*(cnt+1)/2;
                cnt=1;
            }
        }
        res+=cnt*(cnt+1)/2; 
        return res;
    }
};