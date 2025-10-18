class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int digits = s.size(), ans = 0;
        for (int i = 1; i < digits; i++) {
            int x = 9, k = 9;
            for (int j = 1; j < i ; j++) {
                x *= k;
                k--;
            }
            ans += x;
            cout<<ans<<endl;
        }
        vector<int> done(10, 0);
        for (int i = 0; i < digits; i++) {
            int smaller = 0;
            for (int j = 0; j < s[i] - '0'; j++){
                if (!done[j])  smaller++;
            }
            if (i == 0) smaller--;
            int res = 1, rem = 9 - i;
            for (int j = i + 1; j < digits; j++) {
                res *= rem;
                rem--;
            }
            ans += smaller * res;
            if (!done[s[i] - '0'])
                done[s[i] - '0'] = 1;
            else
                return ans;
        }
        return ans +1;
    }
};