class Solution {
public:
    bool isprime(int n){
        if (n <= 1)
        return false;

    // Check if n is 2 or 3
    if (n == 2 || n == 3)
        return true;

    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>p;
        for(int i=max(2,left);i<=right;i++){
            if(isprime(i)) p.push_back(i);
        }
        if(p.size()<2) return {-1,-1};
        int mingap=INT_MAX;
        vector<int>res={-1,-1};
        for(int i=1;i<p.size();i++){
            int gap=p[i]-p[i-1];
            if(gap<mingap){
                mingap=gap;
                res={p[i-1],p[i]};
            }
        }
        return res;
    }
};