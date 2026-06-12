class Solution {
public:
    bool isValid(long long n, long long a, long long b, long long ab, int cnt1,
                 int cnt2) {
        cnt2 = max(0ll, cnt2 - n / a + n / ab);
        cnt1 = max(0ll, cnt1 - n / b + n / ab);
        long long rem = n - (n / a - n / ab + n / b - n / ab + n / ab);
        return rem >= cnt1 + cnt2;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2) {
        long long low = 1;
        long long high = 1e10;
        long long ab = (1ll * divisor1 * divisor2) / gcd(divisor1, divisor2);
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (isValid(mid, divisor1, divisor2, ab, uniqueCnt1, uniqueCnt2))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};