class Solution {
public:
    int a1=0,a2=0,mini=INT_MAX;
    void divisiors(int n){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(abs(i-(n/i))<mini){
                    a1=i;
                    a2=n/i;
                    mini=abs(i-(n/i));
                }
            }
        }
    }
    vector<int> closestDivisors(int num) {
        divisiors(num+1);
        divisiors(num+2);
        return {a1,a2};
    }
};