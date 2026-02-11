class Solution {
public:
    vector<int>Primes(int n){
        vector<int>primes;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                primes.push_back(i);
                while(n%i==0) n/=i;
            }
        }
        if(n>1) primes.push_back(n);
        return primes;
    }
    int findValidSplit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>last;
        for(int i=0;i<n;i++){
            vector<int>primes=Primes(nums[i]);
            for(int p:primes)last[p]=i;
        }
        int r=0;
        for(int i=0;i<n-1;i++){
            vector<int>primes=Primes(nums[i]);
            for(int p:primes) r=max(r,last[p]);
            if(i==r) return i;
        }
        return -1;
    }
};