class Solution {
public:
    vector<long long>f;
    void fib(int a){
        a++;
        f.push_back(1);
        f.push_back(2);
        int i=1;
        while(f[i]+f[i-1]<=a){
            f.push_back(f[i]+f[i-1]);
            i++;
        }
    }
    int cnt(int k){
        int count=0;
        for (int i=f.size()-1;i>=0 && k>0;i--){
            if (f[i]<=k) {
                k-=f[i];
                count++;
            }
        }
        return count;
    }
    int findMinFibonacciNumbers(int k) {
        fib(k);
        return cnt(k);
    }
};