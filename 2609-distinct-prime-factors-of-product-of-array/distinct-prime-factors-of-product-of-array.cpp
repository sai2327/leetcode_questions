class Solution {
public:
    
    
    void linear_sieve(vector<int>&spf,vector<int>&primes){
        for(int i=2;i<=1e5;i++){
            if(spf[i]==0){
                spf[i]=i;
                primes.push_back(i);
            }
            for(int j=0;j<primes.size() and primes[j]<=spf[i] and i*primes[j]<=1e5;j++){
                spf[i*primes[j]]=primes[j];
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int>primes;
        vector<int>spf(1e5+1,0);
        linear_sieve(spf,primes);
        set<int>st;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>1){
                int p=spf[nums[i]];
                st.insert(p);
                while(p==spf[nums[i]]){
                    nums[i]/=p;
                }
            }
        }
        return st.size();
    }
};