class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end()); 
        long long total = 0;
        for(long long b : batteries) total += b; 
        int i = batteries.size() - 1;
        while (i >= 0 && batteries[i] > total / n) {
            total -= batteries[i];  
            n--; 
            i--;
        }
        return total / n;
    }
};