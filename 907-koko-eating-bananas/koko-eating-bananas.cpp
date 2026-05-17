class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.back(),start=1,end=piles.back();
        int ans=piles.back();
        while(start<=end){
            int mid=(start+end)/2;
            long long res=0;
            for(int i:piles)res+=(i+mid-1)/mid;
            if(res<=h){
                ans=mid;
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return ans;
    }
};