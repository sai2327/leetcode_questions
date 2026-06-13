class Solution {
public:
    long long sumoffactors(int n){
        int d=2;
        long long ans=0;
        while(n>1){
            while(n%d==0){
                ans+=d;
                n/=d;
            }
            d++;
        }
        return ans;
    }
    int smallestValue(int n) {
        while(true){
            int sum=sumoffactors(n);
            if(n==sum)break;
            n=sum;
        }
        return n;
    }
};