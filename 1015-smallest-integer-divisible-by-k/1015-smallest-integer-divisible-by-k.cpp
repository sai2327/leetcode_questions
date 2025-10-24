class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int curr=0;
        for (int i = 1; i <= k; i++) {
            
            curr = (curr * 10 + 1) % k;
            cout<<curr<<" ";
            if (!curr)
                return i;
        }
        return -1;
    }
};