class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(),h.rend());
        long long total=0;
        for(int i=0;i<k;i++){
            int res=h[i] - i;
            if(res<=0) break;
            total+=res;
        }
        return total;
    }
};